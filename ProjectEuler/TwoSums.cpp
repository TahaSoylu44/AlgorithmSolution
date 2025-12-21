#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    int aim;
    int element;
    unordered_map<int, int> myMap;

    for (int i = 0; i < nums.size(); i++)
    {
        element = nums[i];
        aim = target - element;
        auto it = myMap.find(aim);

        if (it != myMap.end()) return {myMap[aim], i}; 
        myMap.insert({element, i});
    } 
    return {};
}

int main() {
    
    vector<int> myVector = {2, 7, 11, 15};
    vector<int> result = twoSum(myVector, 18);

    for (int i = 0; i < result.size(); i++) std::cout << result[i] << " ";
    
    return 0;
}