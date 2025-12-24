#include <iostream>
#include <vector>

using namespace std;

int helper(int amount, vector<int>& coins, vector<vector<int>>& dp, int idx)
{
    if (amount == 0) return 1;
    if (amount < 0) return 0;

    if (dp[amount][idx] != -1) return dp[amount][idx];

    int quantitiy = 0;

    for (int i = idx; i < coins.size(); i++)
    {
        quantitiy += helper(amount - coins[i], coins, dp, i);
    } 
    return dp[amount][idx] = quantitiy;
}

int change(int amount, vector<int>& coins)
{
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
    return helper(amount, coins, dp, 0);
}

int main() {

    vector<int> v = {1,2};
    std::cout << change(3, v);
    
    return 0;
}