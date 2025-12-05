#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];

    if (sum % 2 == 0)
    {
        vector<int> cache;
        vector<int> seen(sum, false);
        cache.push_back(0);
        seen[0] = true;
        int size;
        int element;
        int added;

        for (int i = 0; i < nums.size(); i++)
        {
            element = nums[i];
            size = cache.size();

            for (int j = 0; j < size; j++)
            {
                added = element + cache[j];
                if (added == sum/2) return true;

                if(added >= sum)
                {
                    cache.push_back(added);
                }
                else
                {
                    if(!seen[added])
                    {
                        cache.push_back(added);
                        seen[added] = true;
                    } 
                }
            } 
        }
        return false;
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