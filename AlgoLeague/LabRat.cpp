#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<vector<char>>& labmap, int R, int C)
{
    pair<int, int> node = {1,1};
    queue<pair<pair<int, int>, int>> q;
    q.push({node, 0});

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[1][1] = true;
    pair<int, int> newNode;

    while (!q.empty())
    {
        pair<pair<int, int>, int> mypair = q.front();
        q.pop();
        node = mypair.first;

        if (node.first == R - 2 && node.second == C - 2) return mypair.second;  // vardik

        char c = labmap[node.first][node.second];

        if (c == '+')
        {
            // yukari
            if (labmap[node.first - 1][node.second] == '+' || labmap[node.first - 1][node.second] == '|')
            {
                newNode = {node.first - 1, node.second};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }

            // asagi
            if (labmap[node.first + 1][node.second] == '+' || labmap[node.first + 1][node.second] == '|')
            {
                newNode = {node.first + 1, node.second};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }

            // sağ
            if (labmap[node.first][node.second + 1] == '+' || labmap[node.first][node.second + 1] == '-')
            {
                newNode = {node.first, node.second + 1};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }

            // sol
            if (labmap[node.first][node.second - 1] == '+' || labmap[node.first][node.second - 1] == '-')
            {
                newNode = {node.first, node.second - 1};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }
        }
        else if (c == '-')
        {
            // sağ
            if (labmap[node.first][node.second + 1] == '+' || labmap[node.first][node.second + 1] == '-')
            {
                newNode = {node.first, node.second + 1};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }

            // sol
            if (labmap[node.first][node.second - 1] == '+' || labmap[node.first][node.second - 1] == '-')
            {
                newNode = {node.first, node.second - 1};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }
        }
        else if (c == '|')
        {
            // yukari
            if (labmap[node.first - 1][node.second] == '+' || labmap[node.first - 1][node.second] == '|')
            {
                newNode = {node.first - 1, node.second};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }

            // asagi
            if (labmap[node.first + 1][node.second] == '+' || labmap[node.first + 1][node.second] == '|')
            {
                newNode = {node.first + 1, node.second};

                if (!visited[newNode.first][newNode.second])
                {
                    q.push({newNode, mypair.second + 1});
                    visited[newNode.first][newNode.second] = true;
                }
            }
        }
    }

    return -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<vector<char>> labmap(R + 2, vector<char>(C + 2, 'x'));

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> labmap[i][j];
        }
    }

    std::cout << solve(labmap, R + 2, C + 2);
    
    return 0;
}