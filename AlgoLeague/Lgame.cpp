#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(int n, int extra, vector<vector<int>>& dp)
{   
    std::cout << "n: " << n << " extra: " << extra << '\n';
    
    if (dp[n][extra] != -1) return dp[n][extra];
    if ((2 * n + extra) < 3) return dp[n][extra] = 1;
    int opt1 = 0;
    int opt2 = 0;
    int opt3 = 0;

    if (extra) opt3 = helper(n - 1, 0, dp);
    if (n >= 2) opt2 = helper(n - 2, 1, dp);
    if (n >= 2) opt1 = helper(n - 2, 0, dp);

    return dp[n][extra] = !(opt1 && opt2 && opt3);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    int result = helper(n, 0, dp);
    if (result) std::cout << "Bora" << '\n';
    else std::cout << "Arda" << '\n';
    
    return 0;
}