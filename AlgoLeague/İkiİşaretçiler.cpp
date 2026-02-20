#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<int>& markets, vector<int> required_items, int required)
{
    int left = 0;
    int minimum = 1e9;

    for (int right = 0; right < markets.size(); right++)
    {
        int current_item = markets[right] - 1;

        if (required_items[current_item] > 0) required--;
        
        required_items[current_item]--;

        while (required == 0)
        {
            minimum = min(minimum, right - left + 1);

            int left_item = markets[left] - 1;

            required_items[left_item]++;

            if (required_items[left_item] > 0) required++;
            
            left++;
        }
    } 
    return minimum;  
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int numOfMarkets, numOfItems;
    cin >> numOfMarkets >> numOfItems;

    vector<int> markets(numOfMarkets);
    vector<int> required_items(numOfItems);

    for (int i = 0; i < numOfMarkets; i++) cin >> markets[i];
    for (int i = 0; i < numOfItems; i++) cin >> required_items[i];

    int required = 0;

    for (int num : required_items) required += num;

    int result = solve(markets, required_items, required);

    if (result == 1e9) std::cout << -1;
    else std::cout << result;
    
    return 0;
}