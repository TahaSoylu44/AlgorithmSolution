#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void bfs(vector<vector<int>>& adj, int& sum, vector<bool>& visited)
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        int number = node.first;
        q.pop();

        if (adj[number].size() == 1 && visited[adj[number].back()])
        {
            sum += node.second;
            continue;
        }

        for (int num : adj[number])
        {
            if (!visited[num])
            {
                q.push({num, node.second + 1});
                visited[num] = true;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfVertices;
    cin >> numOfVertices;

    vector<vector<int>> adj(numOfVertices + 1);

    for (int i = 0; i < numOfVertices - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int sum = 0;

    vector<bool> visited(numOfVertices + 1, false);

    bfs(adj, sum, visited);

    std::cout << 2 * sum;
    
    return 0;
}