#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int minimum_hamle(int a, int b, vector<vector<int>>& dp)
{
    if (dp[a][b] != -1) return dp[a][b];
    if (a % b == 0) return (a/b) - 1;
    if (b % a == 0) return (b/a) - 1;

    int minimum = 1e9;

    for (int i = 1; i <= (a/2); i++)
    {
        int m = minimum_hamle(i, b, dp);
        int n = minimum_hamle(a-i, b, dp);
        minimum = min(minimum, m + n + 1);
    }

    for (int i = 1; i <= (b/2); i++)
    {
        int m = minimum_hamle(a, i, dp);
        int n = minimum_hamle(a, b - i, dp);
        minimum = min(minimum, m + n + 1);
    }

    return dp[a][b] = minimum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    int result = minimum_hamle(a, b, dp);

    std::cout << result;
    
    return 0;
}