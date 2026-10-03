#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int subarraySum(vector<int>& nums, int k)
{
    int counter = 0;
    int current = 0;
    unordered_map<int,int> mymap;
    mymap[0] = 1;

    for (int num : nums)
    {
        current += num;
        if (mymap.count(current - k)) counter += mymap[current - k];
        mymap[current]++;
    }

    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}