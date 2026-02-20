#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> productExceptSelf(vector<int>& nums)
{
    int size = nums.size();

    vector<int> preProductLeft(size + 1);
    preProductLeft[0] = 1;

    for (int i = 0; i < size; i++) preProductLeft[i + 1] = preProductLeft[i] * nums[i];

    vector<int> preProductRight(size + 1);
    preProductRight[0] = 1;

    for (int i = size - 1; i <= 0; i--) preProductLeft[size - i] = preProductLeft[size - i - 1] * nums[i];

    vector<int> result(size);

    for (int i = 0; i < size; i++) result[i] = preProductLeft[i] * preProductRight[size - i - 1];
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}