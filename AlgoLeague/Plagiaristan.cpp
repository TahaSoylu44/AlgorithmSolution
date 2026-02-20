#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size, len;
    cin >> size >> len;

    string s1, s2;
    cin >> s1 >> s2;

    const int ROW = s1.size() + 1;
    const int COLUMN = s2.size() + 1;

    vector<vector<int>> matrix(ROW, vector<int>(COLUMN));

    for (int i = 0; i <= ROW; i++) matrix[i][0] = 0;
    for (int i = 0; i <= COLUMN; i++) matrix[0][i] = 0;

    int canBe;
    int start, end;
    vector<pair<int, int>> s1Array;
    vector<pair<int, int>> s2Array;

    for (int i = 1; i <= ROW; i++)
    {
        for (int j = 1; j <= COLUMN; j++)
        {
            if (s1[i - 1] != s2[j - 1]) matrix[i][j] = 0;
            else matrix[i][j] = matrix[i- 1][j - 1] + 1;

            if (matrix[i][j] == len)
            {
                end = i;
                start = i - len - 1;
                s1Array.push_back({start, end});

                end = j;
                start = j - len - 1;
                s2Array.push_back({start, end});
            }
        }
    }
    
    return 0;
}