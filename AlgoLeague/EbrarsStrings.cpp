#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;

    const int ROW = s1.size();
    const int COLUMN = s2.size();

    vector<vector<int>> matrix(ROW + 1, vector<int>(COLUMN + 1));

    // preprocess

    for (int i = 0; i <= COLUMN; i++) matrix[0][i] = 0;
    for (int i = 0; i <= ROW; i++) matrix[i][0] = 0;

    int canBe;
    int maximum = 0;

    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COLUMN; j++)
        {
            canBe = -1;

            if (s1[i - 1] == s2[j - 1]) canBe = matrix[i - 1][j - 1];
            maximum = max(matrix[i][j - 1], matrix[i - 1][j]);
            maximum = max(maximum, canBe + 1);
            matrix[i][j] = maximum;
        }
    }

    std::cout << matrix[ROW][COLUMN];
    
    return 0;
}