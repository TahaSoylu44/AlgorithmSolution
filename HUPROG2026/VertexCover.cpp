#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(vector<vector<int>>& array, vector<vector<int>>& dp, int vertex, int parent, int connetion)
{
    if (dp[vertex][connetion] != -1) return dp[vertex][connetion];
    int cost2 = 0;
    int cost1 = 0;

    if (connetion)
    {
        for (int num : array[vertex])
        {
            if (num == parent) continue;
            cost1 += helper(array, dp, num, vertex, 1); // aldım
        }

        for (int num : array[vertex])
        {
            if (num == parent) continue;
            cost2 += helper(array, dp, num, vertex, 0); // almadım
        }

        return dp[vertex][connetion] = min(cost1 + 1, cost2);
    }
    else
    {
        for (int num : array[vertex])
        {
            if (num == parent) continue;
            cost1 += helper(array, dp, num, vertex, 1); // aldım
        }

        return dp[vertex][connetion] = cost1 + 1;
    }
}

int solve(vector<vector<int>>& array, vector<vector<int>>& dp)
{
    return helper(array, dp, 1, 0, 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n;
    vector<vector<int>> array(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        array[x].push_back(y);
        array[y].push_back(x);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    std::cout << solve(array, dp);
    
    return 0;
}