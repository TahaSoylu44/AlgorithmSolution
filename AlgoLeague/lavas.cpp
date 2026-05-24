#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int min_cost_djikstra(vector<vector<pair<int,int>>>& adj, int start, int end)
{
    vector<int> cost(adj.size(), 1e9);
    // vector<bool> visited(adj.size(), false);
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    while (!pq.empty())
    {
        pair<int,int> mypair = pq.top();
        pq.pop();

        int index_cost = mypair.first;
        int index = mypair.second;

        // if (visited[index]) continue;
        // visited[index] = true;

        for (pair<int,int> negpair : adj[index])
        {
            int neg = negpair.first;
            int neg_cost = negpair.second;

            if ((index_cost + neg_cost) < (cost[neg]))
            {
                cost[neg] = index_cost + neg_cost;
                pq.push({cost[neg], neg});
            }
        }
    }

    return cost[end];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num_of_vertices, num_of_edges, num_aspava, num_of_queries;
    cin >> num_of_vertices >> num_of_edges >> num_aspava >> num_of_queries;

    vector<vector<pair<int,int>>> adj(num_of_vertices + 1);
    int u, v, w;

    for (int i = 0; i < num_of_edges; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> locations_aspava(num_aspava);
    for (int i = 0; i < num_aspava; i++) cin >> locations_aspava[i];

    int min_cost;
    int loc;

    for (int i = 0; i < num_of_queries; i++)
    {
        cin >> loc;
        min_cost = 1e9;

        for (int asp : locations_aspava)
        {
            min_cost = min(min_cost, min_cost_djikstra(adj, loc, asp));
        }

        std::cout << min_cost << '\n';
    }
    
    return 0;
}