#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void dpModify(vector<int>& array, vector<int>& dp)
{
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] % array[i - 1] == 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else dp[i] = 1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size;
    cin >> size;

    vector<int> array(size);
    vector<int> dp(size);
    dp[0] = 1;

    for (int i = 0; i < size; i++) cin >> array[i];
    dpModify(array, dp);

    int total = 0;
    for (int num : dp) total += num;
    std::cout << total;
    
    return 0;
}