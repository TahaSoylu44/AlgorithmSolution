#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<int>& v)
{
    if (v.empty()) return 0;
    vector<int> dp(v.size());
    dp[0] = 1;
    int max_value;

    for (int i = 1; i < v.size(); i++)
    {
        max_value = 0;

        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i]) max_value = max(max_value, dp[j]);
        }

        dp[i] = max_value + 1;
    }

    max_value = -1;
    for (int num : dp) max_value = max(max_value, num);
    return max_value;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {0,1,0,2,1,3};
    std::cout << solve(v) << '\n';
    
    return 0;
}