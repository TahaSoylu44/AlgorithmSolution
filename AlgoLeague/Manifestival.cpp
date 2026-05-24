#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

class Node
{
    public:
        int index;
        vector<pair<int,int>> edges;
};

int min_cost(vector<Node>& nodelist, int start, int end)
{
    vector<int> cost(nodelist.size(), 1e9);
    vector<bool> visited(nodelist.size(), false);
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    while (!pq.empty())
    {
        pair<int,int> mypair = pq.top();
        pq.pop();

        int index_cost = mypair.first;
        int index = mypair.second;

        if (visited[index]) continue;
        visited[index] = true;

        for (pair<int,int> negpair : nodelist[index].edges)
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
    
    int num_of_bus, num_of_queries;
    vector<int> bus_point;
    bus_point.push_back(0);
    int d;

    for (int i = 0; i < num_of_bus - 1; i++)
    {
        cin >> d;
        int newd = d + bus_point.back();
        bus_point.push_back(newd);
    }

    // *******************************
    vector<pair<int,int>> query_pair;
    int xs, xf;
    int max_final = 0;

    for (int i = 0; i < num_of_queries; i++)
    {
        cin >> xs >> xf;
        max_final = max(max_final, xf);
        query_pair.push_back({xs,xf});
    }

    vector<Node> nodelist(max_final + 1);

    for (int i = max_final; i >= 0; i--)
    {
        Node node = Node();
        node.index = i;
        for (int j = i + 1; j <= max_final; j++) node.edges.push_back({j,2});
    }

    for (int num : bus_point)
    {
        for (int inner_num : bus_point)
        {
            if (num != inner_num) nodelist[num].edges.push_back({inner_num, 1});
        }
    }

    //************************************************** */

    for (pair<int,int> query : query_pair)
    {
        std::cout << min_cost(nodelist, query.first, query.second) << '\n';
    }
    
    return 0;
}