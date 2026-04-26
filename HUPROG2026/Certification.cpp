#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void helper(vector<int>& array, vector<vector<int>>& dp)
{
    for (int i = 2; i < dp[0].size(); i++)  // i -> dp column
    {
        for (int j = 0; j < dp.size(); j++) // j -> dp row
        {
            for (int k = 0; k < j; k++) // k -> array index
            {
                if (array[k] < array[j])
                {
                    dp[j][i] += dp[k][i - 1];
                }
            }
        }
    }
}

int solve(vector<int>& array, int k)
{
    vector<vector<int>> dp(array.size(), vector<int>(k + 1, 0));

    for (int i = 0; i < array.size(); i++) dp[i][1] = 1;
    helper(array, dp);

    int result = 0;

    for (int i = 0; i < array.size(); i++) result += dp[i][k];
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);

    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        string s;
        cin >> s;
        for (char c : s) {
        if (c == '+' || c == '-' || c == '*' || c == ':') {
            count++;
        }
        }
        A[i] = count;
    }

    std::cout << solve(A, k);
    
    return 0;
}