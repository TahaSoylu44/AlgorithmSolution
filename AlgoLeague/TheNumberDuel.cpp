#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

pair<bool,int> helper(int num, vector<pair<bool,int>>& dp)
{
    if (num == 0) return {true,0};

    if (!(dp[num].first == false && dp[num].second == -1)) return dp[num];

    pair<bool,int> opt1 = helper(num - 1, dp);
    pair<bool,int> opt2 = {true,0};

    if (num % 2 == 0) opt2 = helper(num/2, dp);

    if (!opt1.first || (num % 2 == 0) && !opt2.first)
    {
        if (!opt1.first && (num % 2 == 0) && !opt2.first)
        {
            return dp[num] = {true, 1 + min(opt1.second, opt2.second)};
        }
        else if (!opt1.first)
        {
            return dp[num] = {true, 1 + opt1.second};
        }
        else
        {
            return dp[num] = {true, 1 + opt2.second};
        }
    }
    else
    {
        if (num % 2 == 0)
        {
            return dp[num] = {false, 1 + max(opt1.second, opt2.second)};
        }
        else
        {
            return dp[num] = {false, 1 + opt1.second};
        } 
    }
}

int main() {

    int num;
    cin >> num;

    vector<pair<bool,int>> dp(num + 1, {false,-1});

    pair<bool,int> mypair = helper(num, dp);

    bool ayla = mypair.first;

    if (ayla) std::cout << "Ayla " << mypair.second;
    else std::cout << "Boran " << mypair.second;

    return 0;
}