#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % k != 0) return false;
    int target = total / k;
    int size = nums.size();
    
    vector<int> bitmask((1 << size), -1);
    bitmask[0] = 0;

    for (int mask = 0; mask < (1 << size); mask++)
    {
        if (bitmask[mask] != -1)
        {
            for (int i = 0; i < size; i++)
            {
                if ((mask >> i) & 1) continue;
                if (bitmask[mask] + nums[i] > target) continue;

                int new_mask = mask | (1 << i);
                bitmask[new_mask] = (bitmask[mask] + nums[i]) % target;
            }
        }
    }

    return bitmask[(1 << size) - 1] == 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}