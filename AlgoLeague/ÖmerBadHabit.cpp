#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int MOD = 1007;

int helper(vector<vector<int>>& dp, int i, int n, int pass)
{
    if (i == n) return 1;
    if (dp[i][pass] != -1) return dp[i][pass];

    int opt1 = 0;
    int opt2 = 0;

    if (pass < 2)
    {
        if (pass == 0)
        {
            opt1 = helper(dp, i + 1, n, pass + 1);    // geç
        }
        else
        {
            opt1 = helper(dp, i + 1, n, 0); // tokatla
            opt2 = helper(dp, i + 1, n, pass + 1);    // geç
        }
    }
    else
    {
        opt1 = helper(dp, i + 1, n, 0); // tokatla
    }

    return dp[i][pass] = (opt1 + opt2) % MOD;
}

int solve(int n)
{
    vector<vector<int>> dp(n, vector<int>(3, -1));

    int opt1 = helper(dp, 1, n, 0); // tokatla
    int opt2 = helper(dp, 1, n, 1); // geç

    return (opt1 + opt2) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    std::cout << solve(n);
    
    return 0;
}