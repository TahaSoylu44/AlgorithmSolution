#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void rotate(vector<vector<int>>& matrix)
{
    reverse(matrix.begin(), matrix.end());
    int n = matrix.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);
    }
    return;
}

void print(vector<vector<int>>& matrix)
{
    if (matrix.empty()) return;
    
    for (vector<int> v : matrix)
    {
        for (int num : v) std::cout << num << " ";
        std::cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix = {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16}
    };

    print(matrix);
    rotate(matrix);
    print(matrix);    
    
    return 0;
}