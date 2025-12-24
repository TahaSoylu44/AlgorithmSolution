#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

int getSum(vector<int>& nums)
{
    int result = 0;

    for (int i = 0; i < nums.size(); i++) result += nums[i];
    return result;
}

bool canPartition(vector<int>& nums)
{
    int size = std::accumulate(nums.begin(), nums.end(), 0);
    int totalSum = getSum(nums);

    if (totalSum % 2) return false;
    int target = totalSum / 2;

    unordered_set<int> sums;
    unordered_set<int> newSums;
    sums.insert(0);

    int element;
    int newSum;

    for (int i = size - 1; i >= 0; i--)
    {
        element = nums[i];

        for (int num : sums)
        {
            newSum = element + num;
            if (newSum == target) return true;
            if (newSum < target) newSums.insert(newSum);
        }

        sums.insert(newSums.begin(), newSums.end());
        newSums.clear(); 
    } 
    return false;
}

int main() {

    vector<int> v = {1, 5, 11 , 5};
    std::cout << canPartition(v);
    
    return 0;
}