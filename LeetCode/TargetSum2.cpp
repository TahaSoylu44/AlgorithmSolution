#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int ABS(int n)
{
    if (n < 0) return -1 * n;
    else return n;
}

int helper(vector<int>& nums, int target, vector<vector<int>>& dp, int currentSum, int idx, int sumVector)
{
    if (idx == nums.size())
    {
        if (currentSum == target) return 1;
        else return 0;
    }

    if (dp[idx][currentSum + sumVector] != -1) return dp[idx][currentSum + sumVector];

    int opt1 = helper(nums, target, dp, currentSum + nums[idx], idx + 1, sumVector);    // +
    int opt2 = helper(nums, target, dp, currentSum - nums[idx], idx + 1, sumVector);    // -

    return dp[idx][currentSum + sumVector] = opt1 + opt2;
}

int findTargetSumWays(vector<int>& nums, int target)
{
    int sumVector = std::accumulate(nums.begin(), nums.end(), 0);

    if(ABS(target) > sumVector) return 0;

    vector<vector<int>> dp(nums.size(), vector<int>(2 * sumVector + 1, -1));
    return helper(nums, target, dp, 0, 0, sumVector);
}

int main() {

    vector<int> v = {1,1,1,1,1};
    std::cout << findTargetSumWays(v, 3);
    
    return 0;
}