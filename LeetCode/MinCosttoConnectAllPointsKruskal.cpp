#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void show_point(vector<int>& a, vector<int>& b)
{
    std::cout << a[0] << " " << a[1] << " - " << b[0] << " " << b[1] << '\n';
}

int find_parent(int i, vector<int>& parent)
{
    if (parent[i] == i) return i;
    return parent[i] = find_parent(parent[i], parent);
}

int destination(vector<int>& a, vector<int>& b)
{
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int minCostConnectPoints(vector<vector<int>>& points)
{
    int size = points.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    pair<int,pair<int,int>> pq_pair;
    int counter = 0;
    int weight = 0;
    vector<int> parents(size);
    for (int i = 0; i < size; i++) parents[i] = i;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            pq.push({destination(points[i], points[j]) * -1, {i,j}});
        }
    }

    while (!pq.empty() && counter != size - 1)
    {
        pq_pair = pq.top();
        pq.pop();

        int parentA = find_parent(pq_pair.second.first, parents);
        int parentB = find_parent(pq_pair.second.second, parents);

        if (parentA == parentB) continue;

        weight += (pq_pair.first * -1);
        parents[parentB] = parentA;
        counter++;
    }
    return weight;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> points = {{2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
    std::cout << minCostConnectPoints(points) << '\n';
    
    return 0;
}