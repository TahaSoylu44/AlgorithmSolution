#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void show_point(vector<int> v)
{
    std::cout << v[0] << " " << v[1] << '\n';
}

int destination(vector<int>& a, vector<int>& b)
{
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>>& points)
{
    int numOfNodes = points.size();
    int counter = 0;
    int weight = 0;
    priority_queue<pair<int, vector<int>>> pq;
    set<vector<int>> visited;
    vector<int> point = points[0];
    visited.insert(points[0]);
    pair<int, vector<int>> pq_pair;

    for (int i = 1; i < numOfNodes; i++)
    {
        pq.push({destination(points[0], points[i]) * -1, points[i]});
    }

    while (counter != numOfNodes - 1)
    {
        pq_pair = pq.top();
        pq.pop();
        point = pq_pair.second;
        if (visited.count(point)) continue;
        weight += (pq_pair.first * -1);
        counter++;
        visited.insert(point);

        for (int i = 0; i < numOfNodes; i++)
        {
            if (visited.count(points[i]) == 0)
            {
                pq.push({destination(point, points[i]) * -1, points[i]});
            }
        }
    }
    return weight;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    std::cout << minCostConnectPoints(points) << '\n';
    
    return 0;
}