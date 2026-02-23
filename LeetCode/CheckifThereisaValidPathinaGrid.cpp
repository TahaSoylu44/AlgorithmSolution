#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool hasValidPath(vector<vector<int>>& grid)
{
    int R = grid.size();
    int C = grid[0].size();

    pair<int, int> node = {0,0};
    queue<pair<int, int>> q;
    q.push(node);

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[0][0] = true;
    int cell;

    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, 1, -1, 0};

    vector<vector<int>> pipes = 
    {
        {},
        {1,2},
        {0,3},
        {2,3},
        {1,3},
        {0,2},
        {0,1}
    };

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (node.first == R - 1 && node.second == C - 1) return true;

        cell = grid[node.first][node.second];

        for (int next_dir : pipes[cell])
        {
            bool connectivity = false;
            int nr = node.first + dr[next_dir];
            int nc = node.second + dc[next_dir];

            if (nr < R && nr > -1 && nc < C && nc > -1 && !visited[nr][nc])
            {
                for (int excp_dir : pipes[grid[nr][nc]])
                {
                    if (excp_dir == (3 - next_dir)) 
                    {
                        connectivity = true;
                        break;
                    }
                }
            }

            if (connectivity)
            {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix = {{2, 4, 3},{6, 5, 2}};
    std::cout << hasValidPath(matrix);
    
    return 0;
}