#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<vector<int>>& tree, int wanted, vector<bool>& visited)
{
    if (wanted == 1) return 0;

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int num : tree[node.first])
        {
            if (!visited[num])
            {
                if (num == wanted) return node.second + 1;

                q.push({num, node.second + 1});
                visited[num] = true;
            }
        }
    }
    return -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfnodes, wanted;
    cin >> numOfnodes;

    vector<vector<int>> tree(numOfnodes + 1);

    for (int i = 2; i <= numOfnodes; i++)
    {
        int x;
        cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }

    cin >> wanted;

    vector<bool> visited(numOfnodes + 1, false);

    std::cout << solve(tree, wanted, visited);
    
    return 0;
}