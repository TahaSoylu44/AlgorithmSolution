#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

class Node
{
    public:
        int var = 1e9;
        int where = -1;
};

int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word2.length() + 1, vector<int>(word1.length() + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= word1.length(); i++) dp[0][i] = i;
    for (int i = 1; i <= word2.length(); i++) dp[i][0] = i;

    for (int i = 1; i <= word2.length(); i++)
    {
        for (int j = 1; j <= word1.length(); j++)
        {
            if (word1[j - 1] == word2[i - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    return dp[word2.length()][word1.length()];
}

void print_matrix(vector<vector<Node>>& array)
{
    if (array.empty()) return;

    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[0].size(); j++)
        {
            std::cout << array[i][j].var << " ";
        }
        std::cout << '\n';
    }
}

void minDistanceBackTrace(string word1, string word2)
{
    vector<vector<Node>> dp(word2.length() + 1, vector<Node>(word1.length() + 1));
    dp[0][0].var = 0;
    for (int i = 1; i <= word1.length(); i++) dp[0][i].var = i;
    for (int i = 1; i <= word2.length(); i++) dp[i][0].var = i;

    for (int i = 1; i <= word2.length(); i++)
    {
        for (int j = 1; j <= word1.length(); j++)
        {
            int where;
            int min_value = 1e9;
            int value;

            if (word1[j - 1] == word2[i - 1]) value = dp[i - 1][j - 1].var;
            else value = dp[i - 1][j - 1].var + 1;

            if (value < min_value)
            {
                min_value = value;
                where = 2;  // diag
            }

            value = dp[i - 1][j].var + 1;

            if (value < min_value)
            {
                min_value = value;
                where = 0;  // up
            }

            value = dp[i][j - 1].var + 1;

            if (value < min_value)
            {
                min_value = value;
                where = 1;  // left
            }

            dp[i][j].var = min_value;
            dp[i][j].where = where;
        }
    }

    int i = word2.length();
    int j = word1.length();

    while ((i >= 0) && (j >= 0) && (dp[i][j].where != -1))
    {
        std::cout << "i: " << i << " j: " << j << '\n';

        int where = dp[i][j].where;

        if (where == 0) // up
        {
            i--;
        }
        else if (where == 1)    // left
        {
            j--;
        }
        else if (where == 2)    // diag
        {
            i--;
            j--;
        }
    }

    print_matrix(dp);

    std::cout << "result: " << dp[word2.length()][word1.length()].var << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    minDistanceBackTrace(a,b);

    std::cout << "must be: " << minDistance(a,b) << '\n';
    
    return 0;
}