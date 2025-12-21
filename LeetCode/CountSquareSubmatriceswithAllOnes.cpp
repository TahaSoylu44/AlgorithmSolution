#include <iostream>
#include <vector>

using namespace std;

int getMin(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c) return a;
        else return c;
    }
    else
    {
        if (b < c) return b;
        else return c;
    } 
}

int calculateEdges(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j)
{
    if (i == -1) return 0;
    if (j == -1) return 0;

    if (dp[i][j] == -1)
    {
        if (matrix[i][j] == 0) dp[i][j] = 0;
        else
        {
            dp[i][j] = getMin(calculateEdges(matrix, dp, i - 1, j), calculateEdges(matrix, dp, i - 1, j - 1), calculateEdges(matrix, dp, i, j - 1)) + 1;
        } 
    }
    return dp[i][j];
}

int countSquares(vector<vector<int>>& matrix)
{
    int ROW = matrix.size();
    int COLUMN = matrix[0].size();

    vector<vector<int>> dp(ROW, vector<int>(COLUMN, -1));

    int count = 0;
    int value;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            count += calculateEdges(matrix, dp, i , j);
        } 
    }
    return count;
}

int main() {
    
    return 0;
}