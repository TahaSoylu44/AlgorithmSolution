#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<vector<int>>& adjacencyList, vector<bool>& visited)
{
    queue<int> q;
    int counter = 0;

    for (int i = 1; i < adjacencyList.size(); i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        counter++;
        q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int num : adjacencyList[node])
            {
                if (!visited[num])
                {
                    q.push(num);
                    visited[num] = true;
                }
            }
        }
    }
    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjacencyList(N + 1);

    for (int i = 0; i < M; i++)
    {
        int node, neighbour;
        cin >> node >> neighbour;

        adjacencyList[node].push_back(neighbour);
        adjacencyList[neighbour].push_back(node);
    }

    vector<bool> visited(N + 1, false);
    std::cout << solve(adjacencyList, visited);
    
    return 0;
}