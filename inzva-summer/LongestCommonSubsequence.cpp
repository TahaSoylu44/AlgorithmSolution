#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));

    vector<int> v1(n);
    vector<int> v2(m);

    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < m; i++) cin >> v2[i];

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (v1[i - 1] == v2[j - 1]) matrix[j][i] = matrix[j - 1][i - 1] + 1;
            else matrix[j][i] = max(matrix[j - 1][i], matrix[j][i - 1]);
        }
    }

    std::cout << matrix[m][n];
    
    return 0;
}