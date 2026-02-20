#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<vector<int>>& tree, vector<int>& dp, int node)
{
    if (dp[node] != -1) return dp[node];
    if (tree[node].empty()) return dp[node] = 1;

    int counter = 0;

    for (int num : tree[node]) counter += solve(tree, dp, num);
    return dp[node] = counter + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfNodes, wanted;
    cin >> numOfNodes;

    vector<vector<int>> tree(numOfNodes + 1);
    vector<int> dp(numOfNodes + 1, -1);

    for (int i = 2; i <= numOfNodes; i++)
    {
        int x;
        cin >> x;
        tree[x].push_back(i);
    }

    cin >> wanted;
    int all = solve(tree, dp, 1);

    std::cout << dp[wanted];
    
    return 0;
}