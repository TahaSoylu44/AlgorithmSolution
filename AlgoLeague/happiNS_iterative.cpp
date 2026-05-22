#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<vector<int>>& table)
{
    int max_one;

    for (int i = table.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            max_one = 0;

            for (int k = 0; k < 3; k++)
            {
                if (j != k) max_one = max(max_one, table[i + 1][k]);
            }

            table[i][j] += max_one;
        }
    }

    int max_value = 0;
    for (int i = 0; i < 3; i++) max_value = max(max_value, table[0][i]);
    return max_value;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a, b, c;
    cin >> n;
    
    vector<vector<int>> table(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        table[i][0] = a;
        table[i][1] = b;
        table[i][2] = c;
    }

    std::cout << solve(table) << '\n';
    
    return 0;
}