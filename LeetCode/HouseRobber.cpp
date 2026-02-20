#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(vector<int>& nums, int index, int GET, vector<vector<int>>& dp)
{
    if (index == nums.size()) return 0;
    if (dp[index][GET] != -1) return dp[index][GET];

    if (GET) return dp[index][GET] = helper(nums, index + 1, 0, dp);
    else
    {
        int opt1 = nums[index] + helper(nums, index + 1, 1, dp);    // aldım
        int opt2 = helper(nums, index + 1, 0, dp);  // almadım

        return dp[index][GET] = max(opt1, opt2);
    }
}

int rob(vector<int>& nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(2, -1));

    return helper(nums, 0, 0, dp);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2,7,9,3,1};
    std::cout << rob(nums);
    
    return 0;
}