#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(vector<vector<int>>& table, vector<vector<int>>& dp, int row, int forbiden_column)
{
    if (row == table.size() - 1) return 0;
    if (dp[row][forbiden_column] != -1) return dp[row][forbiden_column];

    int opt1, opt2;

    if (forbiden_column == 0)
    {
        opt1 = table[row + 1][1] + helper(table, dp, row + 1, 1);
        opt2 = table[row + 1][2] + helper(table, dp, row + 1, 2);
    }
    else if (forbiden_column == 1)
    {
        opt1 = table[row + 1][0] + helper(table, dp, row + 1, 0);
        opt2 = table[row + 1][2] + helper(table, dp, row + 1, 2);
    }
    else if (forbiden_column == 2)
    {
        opt1 = table[row + 1][1] + helper(table, dp, row + 1, 1);
        opt2 = table[row + 1][0] + helper(table, dp, row + 1, 0);
    }

    return dp[row][forbiden_column] = max(opt1, opt2);
}

int solve(vector<vector<int>>& table, vector<vector<int>>& dp)
{
    int opt1 = table[0][0] + helper(table, dp, 0, 0);
    int opt2 = table[0][1] + helper(table, dp, 0, 1);
    int opt3 = table[0][2] + helper(table, dp, 0, 2);

    int max_value = max(opt1, opt2);
    return max(max_value, opt3);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b, c;
    cin >> n;
    
    vector<vector<int>> table(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        table[i][0] = a;
        table[i][1] = b;
        table[i][2] = c;
    }

    vector<vector<int>> dp(n, vector<int>(3, -1));
    std::cout << solve(table, dp) << '\n';

    return 0;
}