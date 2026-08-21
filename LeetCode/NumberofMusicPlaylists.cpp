#include <vector>

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        int MOD = 1e9 + 7;

        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));

        dp[0][0] = 1;

        for (int i = 0; i < goal; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j < n) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + ((dp[i][j] * (n - j)) % MOD)) % MOD;
                if (k < j) dp[i + 1][j] = (dp[i + 1][j] + ((dp[i][j] * (j - k)) % MOD)) % MOD;
            }
        }

        return dp[goal][n];
    }
};