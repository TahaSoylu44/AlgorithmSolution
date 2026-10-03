#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int minDistance(string word1, string word2)
{
    int m = word1.length() + 1;
    int n = word2.length() + 1;
    vector<vector<int>> table(n, vector<int>(m, 0));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (word2[i - 1] == word1[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    int max_length = table[n - 1][m - 1];

    if (max_length != 0) return (n + m - 2 * max_length - 2);
    else return n + m - 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    std::cout << minDistance("a","b") << '\n';    
    
    return 0;
}