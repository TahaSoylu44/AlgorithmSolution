#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void bfs(vector<vector<int>>& adj, vector<bool>& visited)
{
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int from = q.front();

        std::cout << from << '\n';

        q.pop();
        if (visited[from]) continue;
        visited[from] = 1;

        for (int to : adj[from])
        {
            if (visited[to]) continue;
            q.push(to);
        }
    }
}

void dfsStack(vector<vector<int>>& adj, vector<bool>& visited)
{
    stack<int> s;
    s.push(0);

    while (!s.empty())
    {
        int from = s.top();

        std::cout << from << '\n';

        s.pop();
        if (visited[from]) continue;

        visited[from] = true;

        for (int to : adj[from])
        {
            if (visited[to]) continue;
            s.push(to);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /*
    N -> Node sayısı
    M -> Edge sayısı
    (M satır) A < - > B
    */

    int N, M; cin >> N >> M;

    vector<vector<int>> adj(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++)
    {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    return 0;
}