#include <iostream>
#include <vector>

using namespace std;

int getAverage(vector<vector<int>>& matrix, int i, int j, int ROW, int COLUMN)
{
    int up, right, down, left;
    int counter = 0;

    if (i > 0)
    {
        up = matrix[i - 1][j];
        counter++;
    }
    else up = 0;

    if (j <= COLUMN - 2)
    {
        right = matrix[i][j + 1];
        counter++;
    }
    else right = 0;

    if (i <= ROW - 2)
    {
        down = matrix[i + 1][j];
        counter++;
    }
    else down = 0;

    if (j > 0)
    {
        left = matrix[i][j - 1];
        counter++;
    }
    else left = 0;

    if (counter) return (up + right + down + left) / counter;
    else return 0;
}

vector<vector<int>> imageProcessing(vector<vector<int>>& matrix)
{
    int ROW = matrix.size();
    int COLUMN = matrix[0].size();
    vector<vector<int>> copyMatrix(ROW, vector<int>(COLUMN));

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            copyMatrix[i][j] = getAverage(matrix, i, j, ROW, COLUMN);
        }
    } 
    return copyMatrix;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row;
    int column;
    int step;

    vector<int> parameters(3);

    for (int i = 0; i < 3; i++) cin >> parameters[i];

    row = parameters[0];
    column = parameters[1];
    step = parameters[2];

    vector<vector<int>> matrix(row, vector<int>(column));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
        } 
    }

    vector<vector<int>> copyMatrix;

    int counter = 0;

    while (counter < step)
    {
        copyMatrix = imageProcessing(matrix);
        matrix = copyMatrix;
        counter++;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
    
    return 0;
}