#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(vector<int>& dp, int job, vector<vector<int>>& connections, vector<int>& profit)
{
    if (dp[job] != -1) return dp[job];
    if (connections[job].empty()) return dp[job] = profit[job];

    int value = 0;

    for (int connection : connections[job])
    {
        value = max(value, helper(dp, connection, connections, profit));
    }

    return dp[job] = profit[job] + value;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
    int numOfJobs = startTime.size();
    vector<vector<int>> connections(numOfJobs);

    for (int i = 0; i < numOfJobs; i++)
    {
        for (int j = i + 1; j < numOfJobs; j++)
        {
            if (startTime[j] >= endTime[i])
            {
                connections[i].push_back(j);
            }
        }
    }

    vector<int> dp(numOfJobs, -1);
    int max_value = 0;

    for (int i = 0; i < numOfJobs; i++) max_value = max(max_value, helper(dp, i, connections, profit));
    return max_value;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};

    std::cout << jobScheduling(startTime, endTime, profit) << '\n';
    
    return 0;
}