#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> productExceptSelf(vector<int>& nums)
{
    int product = 1;
    int numOFZeroes = 0;

    for (int num : nums)
    {
        if (num == 0) numOFZeroes++;
        else product *= num;
    }

    vector<int> result(nums.size());

    if (numOFZeroes)
    {
        int number;
        
        for (int i = 0; i < nums.size(); i++)
        {
            number = nums[i];

            if (number == 0)
            {
                if (numOFZeroes > 1) result[i] = 0;
                else result[i] = product;
            }
            else result[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < nums.size(); i++) result[i] = product / nums[i];
    }

    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}