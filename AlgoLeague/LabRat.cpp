#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(vector<vector<char>>& matrix, vector<vector<int>>& dp, int row, int column, int step, int R, int C, char c, int movement)
{
    if (row == R && column == C) return step;
    if (matrix[row][column] == 'x') return 1e9;
    if (dp[row][column] != -1) return dp[row][column];

    char now = matrix[row][column];

    int opt1 = 1e9;
    int opt2 = 1e9;
    int opt3 = 1e9;
    int opt4 = 1e9;

    if (now == '+')
    {
        if (movement)   // dikey
        {
            if (now == '+')
            {
                // olur
            }
            else if (now == '|')
            {
                // olur
            }
            else    // olmaz
            {
                /* code */
            }
        }
        else    // yatay
        {
            if (now == '+')
            {
                // olur
            }
            else if (now == '-')
            {
                // olur
            }
            else    // olmaz
            {
                /* code */
            }
        }
    }
    else if (now == '-')
    {
        if (movement)   // dikey
        {
            return 1e9;
        }
        else    // yatay
        {
            // olur
        }
    }
    else if (now == '|')
    {
        if (movement)   // dikey
        {
            // olur
        }
        else    // yatay
        {
            return 1e9;
        }
    }
}

int solve(vector<vector<char>>& matrix, int R, int C)
{
    vector<vector<int>> dp(R + 2, vector<int>(C + 2, -1));

    return helper(matrix, dp, 1, 1, 1, R, C);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C;
    cin >> R >> C;

    vector<vector<char>> matrix(R + 2, vector<char>(C + 2, 'x'));

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    return 0;
}