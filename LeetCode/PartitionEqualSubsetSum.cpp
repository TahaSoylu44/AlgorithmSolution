/*
tamam bu sorudan şunu öğrendik.
Gerekli toplamı elde etmek için elimde iki seçenek var.
Ya sıradaki değeri seçerim ya da seçmem.
Ayrı ayrı iki option olacak şekilde bunların sonucunu hesaplayıp or kapısına sokarım.
Eğer en az bir tanesi doğru geliyorsa o zaman array ikiye ayrılabilir.
*/

#include <iostream>
#include <vector>

using namespace std;

int getSum(vector<int>& nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++) result += nums[i];
    return result;
}

bool helper(vector<int>& nums, int left, int target, vector<vector<int>>& dp)
{
    if (left == nums.size()) return false;
    if (target < 0) return false;
    if (left == nums.size() - 1) return nums[left] == target;

    if(dp[left][target] == -1)
    {
        bool opt1 = helper(nums, left + 1, target - nums[left], dp);    //değeri al
        bool opt2 = helper(nums, left + 1, target, dp); //değeri alma
        dp[left][target] = opt1 || opt2;
    }
    return dp[left][target];
}

bool canPartition(vector<int>& nums)
{
    int sum = getSum(nums);
    int size = nums.size();
    int target = sum / 2;

    vector<vector<int>> dp(size, vector<int>(target + 1, -1));
    
    if (sum % 2 == 0)
    {
        return helper(nums, 0, target, dp);
    }
    else
    {
        return false;
    } 
}

int main() {
    
    vector<int> myarr = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};

    std::cout << canPartition(myarr) << std::endl;

    return 0;
}