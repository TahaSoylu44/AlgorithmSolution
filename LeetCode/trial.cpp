#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(int pos, int mod, vector<vector<int>>& dp, vector<int>& nums)
{
    if (pos == nums.size()) return 0;
    if (dp[pos][mod] != -1) return dp[pos][mod];

    int opt1 = helper(pos + 1, (mod + nums[pos]) % 3, dp, nums);    // al
    int opt2 = helper(pos + 1, mod, dp, nums);    // alma

    return dp[pos][mod] = max(opt1, opt2);
}

void func(vector<int>& nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(3, -1));

    return helper(0, )
}

int main() {
    
    return 0;
}