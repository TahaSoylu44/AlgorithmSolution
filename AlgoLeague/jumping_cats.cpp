#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void solve(vector<vector<int>>& matrix, vector<int>& own_duration, vector<int>& dp)
{
    dp[matrix[0][0]] = own_duration[matrix[0][0]];
    pair<int,int> opt1;
    pair<int,int> opt2;
    int opt1_value, opt2_value;

    int m = matrix.size();

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            opt1 = {i - 1, j - 1};
            opt2 = {i - 1, j};

            // opt1 incelemesi
            if (opt1.second < 0) opt1_value = 1e18;
            else opt1_value = dp[matrix[opt1.first][opt1.second]];

            // opt2 incelemesi
            if (opt2.second >= i) opt2_value = 1e18;
            else opt2_value = dp[matrix[opt2.first][opt2.second]];

            dp[matrix[i][j]] = min(opt1_value, opt2_value) + own_duration[matrix[i][j]];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num_of_cat, m; cin >> num_of_cat >> m;
    int number = 1;
    vector<vector<int>> matrix;

    for (int i = 0; i < m; i++)
    {
        vector<int> sub_array;

        for (int j = 0; j < i + 1; j++)
        {
            sub_array.push_back(number);
            number++;
        }

        matrix.push_back(sub_array);
    }

    vector<int> targets(num_of_cat);
    for (int i = 0; i < num_of_cat; i++) cin >> targets[i];

    int size = (m * (m + 1) / 2) + 1;

    vector<int> own_duration(size);
    for (int i = 1; i < size; i++) cin >> own_duration[i];

    vector<int> dp(size, -1);
    solve(matrix, own_duration, dp);

    int counter = 0;
    for (int target : targets) counter += dp[matrix[m - 1][target - 1]];

    std::cout << counter << '\n';
    
    return 0;
}