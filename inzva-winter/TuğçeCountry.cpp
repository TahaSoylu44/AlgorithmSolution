#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void bfs(vector<vector<int>>& adj, vector<bool>& visited, int& counter, int x)
{
    if (visited[x]) return;

    queue<int> q;

    q.push(x);
    visited[x] = true;
    counter++;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int num : adj[node])
        {
            if (visited[num]) continue;
            q.push(num);
            visited[num] = true;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfVertices, numOfEdges;
    cin >> numOfVertices >> numOfEdges;

    vector<vector<int>> adj(numOfVertices + 1);

    for (int i = 0; i < numOfEdges; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(numOfVertices + 1, false);
    int counter = 0;

    for (int i = 1; i <= numOfVertices; i++) bfs(adj, visited, counter, i);

    std::cout << counter;
    
    return 0;
}