/*
"o zaman dp için bir başlangıç değeri belirledik ve bu en üst sol köşe.
Sonra ilk saturu ve ilk sütunu buldum.Ondan sonra iç matrixler için hesaplamalar yaptım.
Her hücrede sol ve yukarının min maliyetlerini hesaplayıp kendi maliyetini ekledim ve en son sağ alt köşeye ulaştım."
*/

#include <iostream>
#include <vector>

using namespace std;

int getMin(int a, int b)
{
    if (a == -1 && b == -1) return 0;
    else if (a == -1) return b;
    else if (b == -1) return a;
    else return (a < b) ? a : b;
}

int minPathSum(vector<vector<int>>& grid)
{
    int ROW = grid.size();
    int COLUMN = grid[0].size();

    vector<vector<int>> dp(ROW, vector<int>(COLUMN, -1));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < COLUMN; i++)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < ROW; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < ROW; i++)
    {
        for (int j = 1; j < COLUMN; j++)
        {
            dp[i][j] = getMin(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        } 
    }

    return dp[ROW - 1][COLUMN - 1];
}


int main() {
    
    vector<vector<int>> grid = 
    {
    {1, 3, 1},
    {1, 5, 1},
    {4, 2, 1}
    };

    std::cout << minPathSum(grid) << std::endl;

    return 0;
}