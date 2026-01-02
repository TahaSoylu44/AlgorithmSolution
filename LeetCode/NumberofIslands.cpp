#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
{
    queue<vector<int>> q;
    q.push({i,j});
    visited[i][j] = true;

    while (!q.empty())
    {
        int row = q.front()[0];
        int column = q.front()[1];
        q.pop();

        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + directions[i][0];
            int newColumn = column + directions[i][1];

            if (newRow < grid.size() && 
                newRow >= 0 &&
                newColumn >= 0 &&
                newColumn < grid[0].size() &&
                grid[newRow][newColumn] == '1' && 
                !visited[newRow][newColumn])

                {
                    q.push({newRow,newColumn});
                    visited[newRow][newColumn] = true;
                }
        } 
    }
}

int numIslands(vector<vector<char>>& grid)
{
    if (grid.empty()) return 0;

    int ROW = grid.size();
    int COLUMN = grid[0].size();
    int numOfIsland = 0;

    vector<vector<bool>> visited(ROW, vector<bool>(COLUMN, false));

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                bfs(grid, visited, i ,j);
                numOfIsland++;
            }
        }
    }
    return  numOfIsland;
}

int main() {
    
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    std::cout << numIslands(grid);

    return 0;
}