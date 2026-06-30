#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int get_num(vector<int>& dp, int node, vector<vector<int>>& adj)
{
    if (dp[node] != -1) return dp[node];
    if (adj[node].empty()) return 1;

    dp[node] = 1;
    for (int child : adj[node]) dp[node] += get_num(dp, child, adj);
    return dp[node];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> dp(4, -1);
    vector<vector<int>> adj(4);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(3);

    std::cout << get_num(dp, 0, adj) << '\n';
    
    return 0;
}