#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& fruits, vector<vector<int>>& dp, int money, int idx)
{
    if (money <= 0) return 0;
    if (idx == fruits.size()) return 0;

    if (dp[idx][money] == -1)
    {
        int opt1;

        if (idx > ((fruits.size() / 2) - 1))
        {
            if (money >= fruits[idx])
            {
                opt1 = (idx - ((fruits.size() / 2) - 1)) + helper(fruits, dp, money - fruits[idx], idx + 1);
            }
            else opt1 = 0;
        } 
        else
        {
            if (money >= fruits[idx])
            {
                opt1 = (idx + 1) + helper(fruits, dp, money - fruits[idx], idx + 1);
            }
            else opt1 = 0;
        }

        int opt2 = helper(fruits, dp, money, idx + 1);

        dp[idx][money] = (opt1 > opt2) ? opt1 : opt2;
    }
    return dp[idx][money];
}

int getMax(vector<int>& fruits, int money)
{
    vector<vector<int>> dp(fruits.size(), vector<int>(money+ 1, -1));
    return helper(fruits, dp, money, 0);
}

int main() {
    vector<int> arr(2);
    for (int i = 0; i < 2; i++) cin >> arr[i];

    int maxKG = arr[0];
    int money = arr[1];

    vector<int> bananas(maxKG);
    vector<int> pineapples(maxKG);
    vector<int> fruits(2* maxKG);

    for (int i = 0; i < maxKG; i++) cin >> bananas[i];
    for (int i = 0; i < maxKG; i++) cin >> pineapples[i];

    for (int i = 0; i < 2 * maxKG; i++)
    {
        if (i < maxKG) fruits[i] = bananas[i];
        else fruits[i] = pineapples[i - maxKG];
    }

    std::cout << getMax(fruits, money);
    
    return 0;
}