#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int maxProfit(vector<int>& prices)
{
    int minBase = prices[0];
    int maximum = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < minBase) minBase = prices[i];
        else maximum = max(prices[i] - minBase, maximum);
    }

    return maximum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}