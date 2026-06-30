#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, R;
    cin >> N >> R;
    vector<int> inDegree(N + 1, 0);
    unordered_set<int> requirements;
    unordered_set<int> requirements_sub;
    vector<int> req_list;
    vector<vector<int>> dependency_list(N + 1);
    vector<int> order;
    vector<vector<int>> ihtiyac_basta(N + 1);

    int installed = 0;

    int num_of_dependicies, dependency;

    for (int i = 1; i <= N; i++)
    {
        cin >> num_of_dependicies;
        inDegree[i] = num_of_dependicies;

        for (int j = 0; j < num_of_dependicies; j++)
        {
            cin >> dependency;
            ihtiyac_basta[dependency].push_back(i);
            dependency_list[i].push_back(dependency);
        }
    }

    int req;

    for (int i = 0; i < R; i++)
    {
        cin >> req;
        requirements.insert(req);
        req_list.push_back(req);
    }

    priority_queue<int> pq_degree_zero;

    for (int req : req_list)
    {
        for (int num : dependency_list[req])
        {
            requirements_sub.insert(num);
            if (inDegree[num] == 0) pq_degree_zero.push(-num);
        }
        if (inDegree[req] == 0) pq_degree_zero.push(-req);
    }

    int node;
    bool isAllInstalled = false;

    while (!pq_degree_zero.empty())
    {
        node = pq_degree_zero.top() * -1;
        order.push_back(node);

        if (requirements.count(node)) installed++;

        if (installed == R)
        {
            isAllInstalled = true;
            break;
        }

        pq_degree_zero.pop();

        for (int num : ihtiyac_basta[node])
        {
            inDegree[num]--;
            if (inDegree[num] == 0)
            {
                if (requirements.count(num) || requirements_sub.count(num)) pq_degree_zero.push(-num);
            }
        }
    }

    if (isAllInstalled)
    {
        for (int num : order) std::cout << num << '\n'; 
    }
    else std::cout << "impossible" << '\n';
    
    return 0;
}