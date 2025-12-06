/*
Öncelikle şunu belirtmeliyim ki bu diğerlerine göre daha zordu.
İlerlediğim mantık şu,her seferinde currentSum tutarak bir sonraki array aramasında 
target nasıl ulaşırım onu hesapladım.Hem ekleme hem de çıkarma için oluşabilecek case leri
hesapladım.Onları bir arrayde tuttum (dp[idx][currentSum]).Negatif sonuçlar gelebilir diye kaydırma yaptım.
Ne zaman array e bir şey eklemek istesem currentSum ı totalSum ile toplayıp index belirliyordum.Böylece
negatif index sorunu kalmıyordu.
*/

#include <iostream>
#include <vector>

using namespace std;

int ABS(int n)
{
    if (n < 0)
    {
        return -1 * n;
    }
    return n;
}

int helper(vector<int>& nums, vector<vector<int>>& dp, int idx, int target, int currentSum, int totalSum)
{
    if (idx == nums.size()) return (currentSum == target) ? 1 : 0;
    
    if (dp[idx][currentSum + totalSum] == -1)
    {
        int add = helper(nums, dp, idx + 1, target, currentSum + nums[idx], totalSum);
        int substract = helper(nums, dp, idx + 1, target, currentSum - nums[idx], totalSum);
        dp[idx][currentSum + totalSum] = add + substract;
    }
    return dp[idx][currentSum + totalSum];
}

int findTargetSumWays(vector<int>& nums, int target)
{
    int sum = 0;
    for (int n : nums) sum+=n;

    if(ABS(target) > sum) return 0;

    vector<vector<int>> dp(nums.size(), vector<int>((2 * sum) + 1, -1));
    return helper(nums, dp, 0 ,target, 0, sum);
}

int main() {
    
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    std::cout << findTargetSumWays(nums, target) << std::endl;

    return 0;
}