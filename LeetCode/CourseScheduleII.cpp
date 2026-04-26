#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void dfs(vector<vector<int>>& adjacency_list, vector<int>& result, vector<bool>& visited, int source)
{
    bool isAllVisited;
    visited[source] = true;
    stack<int> s;
    s.push(source);
    int node;
    int counter = 1;
    unordered_map<int, int> mymap;
    mymap.insert({source,counter});

    while (!s.empty())
    {
        isAllVisited = true;
        node = s.top();
        counter++;

        for (int num : adjacency_list[node])
        {
            if (!visited[num])
            {
                s.push(num);
                mymap.insert({num,counter});
                visited[num] = true;
                isAllVisited = false;
            }
            else
            {
                if (mymap[num] < mymap[node])   // cycle detection
                {
                    result.clear();
                    return;
                }
            }
        }
        if (isAllVisited)
        {
            result.push_back(node);
            s.pop();
        }
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adjacency_list(numCourses);
    int start = -1;

    for (const vector<int> v : prerequisites)
    {
        if (!v.empty()) adjacency_list[v[1]].push_back(v[0]);
        if (start == -1) start = v[1];
    }

    vector<int> result;
    vector<int> reversed;
    vector<bool> visited(numCourses, false);

    dfs(adjacency_list, result, visited, start);

    if (result.empty()) return result;
    for (int i = numCourses - 1; i >= 0; i--) reversed.push_back(result[i]);
    return reversed;
}

void print_vector(vector<int>& v)
{
    for (int num : v) std::cout << num << " ";
    std::cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> empty = {{}};
    vector<vector<int>> prerequisitesss = {{0,1}};
    vector<int> result = findOrder(2, prerequisitesss);
    print_vector(result);
    
    return 0;
}