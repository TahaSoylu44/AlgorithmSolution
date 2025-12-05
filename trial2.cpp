#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target)
{
    vector<int> cache;
    vector<bool> negSeen;
    vector<bool> posSeen;
    cache.push_back(0);

    int element;
    int added1;
    int added2;

    for (int i = 0; i < nums.size(); i++)
    {
        element = nums[i];

        for (int j = 0; j < cache.size(); j++)
        {
            added1 = element + cache[j];
            added2 = (-1 * element) + cache[j];
        } 
    }
}

int main() {
    
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    return 0;
}