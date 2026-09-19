#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> djkstra(vector<vector<pair<int,int>>>& adj, int start)
{
    vector<int> dist(adj.size(), 1e18);
    dist[start] = 0;

    priority_queue<pair<int,int>> myqueue;
    myqueue.push({0,start});

    pair<int,int> node;
    int neg, weight;
    int new_weight;

    while (!myqueue.empty())
    {
        node = myqueue.top();
        myqueue.pop();

        for (pair<int,int> mypair : adj[node.second])
        {
            neg = mypair.first;
            weight = mypair.second;
            new_weight = weight + (node.first * -1);

            if (new_weight < dist[neg])
            {
                dist[neg] = new_weight;
                myqueue.push({-1 * new_weight, neg});
            }
        }
    }

    return dist;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, q;
    int u, v, w;
    int start, asp;
    cin >> n >> m >> a >> q;

    vector<vector<pair<int,int>>> adj(n + 2);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for (int i = 0; i < a; i++)
    {
        cin >> asp;
        adj[n + 1].push_back({asp,0});
        adj[asp].push_back({n + 1,0});
    }

    vector<int> dist = djkstra(adj, n + 1);

    for (int i = 0; i < q; i++)
    {
        cin >> start;
        std::cout << dist[start] << '\n';
    }
    
    return 0;
}