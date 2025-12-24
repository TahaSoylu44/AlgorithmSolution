#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& coins,vector<int>& dp, int amount)
{
    if (amount == 0) return 0;
    if (amount < 0) return 1e9;

    if (dp[amount] != -1) return dp[amount];

    int minValue = 1e9;
    int quantitiy;

    for (int i = 0; i < coins.size(); i++)
    {
        quantitiy = helper(coins, dp, amount - coins[i]);
        if ((quantitiy != 1e9) && (quantitiy + 1 < minValue)) minValue = quantitiy + 1;
    }
    return dp[amount] = minValue;
}

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int result = helper(coins, dp, amount);

    if (result == 1e9) return -1;
    else return result;
}

int main() {
    
    vector<int> v = {1,2,5};
    std::cout << coinChange(v, 11);

    return 0;
}