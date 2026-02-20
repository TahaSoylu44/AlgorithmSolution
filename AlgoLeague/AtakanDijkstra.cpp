#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int shortestPath(vector<vector<pair<int, int>>>& graph)
{
    //
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfVertices, numOfEdges;
    cin >> numOfVertices, numOfEdges;

    vector<vector<pair<int, int>>> graph(numOfVertices + 1);

    int start, end, weight;

    for (int i = 0; i < numOfEdges; i++)
    {
        cin >> start >> end >> weight;

        graph[start].push_back({end, weight});
        graph[end].push_back({start, weight});
    }

    std::cout << shortestPath(graph);
    
    return 0;
}