#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void calculate_locations(vector<vector<int>>& tas_devri, vector<pair<int, int>>& fred_locations, pair<int, int>& fred)
{
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<bool>> visited(tas_devri.size(), vector<bool>(tas_devri.size(), false));
    int x = fred.first;
    int y = fred.second;

    int constant_x = x;
    int constant_y = y;
    pair<int, int> mypair;

    visited[x][y] = true;
    fred_locations.push_back(fred);

    queue<pair<int, int>> q;
    q.push(fred);

    while (!q.empty())
    {
        mypair = q.front();
        q.pop();

        constant_x = mypair.first;
        constant_y = mypair.second;

        for (int i = 0; i < 4; i++)
        {
            x = constant_x + dx[i];
            y = constant_y + dy[i];

            if (tas_devri[x][y])
            {
                if (!visited[x][y])
                {
                    visited[x][y] = true;
                    fred_locations.push_back({x,y});
                    q.push({x,y});
                }
            }
        }
    }
}

int formula(int fx, int fy, int wx, int wy)
{
    return ((fx - wx) * (fx - wx) + (fy - wy) * (fy - wy));
}

int calculate_cost(vector<pair<int, int>>& fred, vector<pair<int, int>>& welma)
{
    int minCost = 1e9;
    int cost;

    for (pair<int, int> fred_pair : fred)
    {
        for (pair<int, int> welma_pair : welma)
        {
            if (fred_pair == welma_pair) return 0;
            cost = formula(fred_pair.first, fred_pair.second, welma_pair.first, welma_pair.second);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string row;
    cin >> n;

    int x1, y1;
    int x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    pair<int, int> fred = {x1,y1};
    pair<int, int> welma = {x2,y2};
    
    vector<vector<int>> tas_devri(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        cin >> row;

        for (int j = 1; j <= n; j++)
        {
            tas_devri[i][j] = row[j - 1] - '0';
        }
    }

    vector<pair<int, int>> fred_locations;
    vector<pair<int, int>> welma_locations;

    calculate_locations(tas_devri, fred_locations, fred);
    calculate_locations(tas_devri, welma_locations, welma);

    std::cout << calculate_cost(fred_locations, welma_locations);
    
    return 0;
}