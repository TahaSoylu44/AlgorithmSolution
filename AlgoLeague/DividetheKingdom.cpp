#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int dfs(vector<vector<int>>& adj, int node, int b, int& num_of_cut, int parent)
{
    int counter = 1;
    for (int neg : adj[node])
    {
        if (neg != parent)
        {
            counter += dfs(adj, neg, b, num_of_cut, node); 
        }
    }

    if (counter >= b)
    {
        num_of_cut++;
        return 0;
    }
    else return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    int a,b;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root = 1;
    int max_node = adj[1].size();

    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() > max_node)
        {
            max_node = adj[i].size();
            root = i;
        }
    }

    int left = 1;
    int right = n / (k + 1);
    int mid;
    int ans = 1;

    while (left <= right)
    {
        int num_of_cuts = 0;
        mid = (left + right) / 2;
        dfs(adj, 1, mid, num_of_cuts, 0);

        if (num_of_cuts <= k) right = mid - 1;
        else 
        {
            ans = mid;
            left = mid + 1;
        }
    }

    std::cout << ans << '\n';
    
    return 0;
}