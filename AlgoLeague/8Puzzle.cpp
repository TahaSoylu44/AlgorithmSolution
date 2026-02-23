#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<vector<int>>& matrix)
{
    string current;
    int r, c;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            current.push_back(matrix[i][j] + '0');

            if (matrix[i][j] == 0)
            {
                r = i;
                c = j;
            }
        }
    }

    vector<int> dx = {0,1,-1,0};
    vector<int> dy = {-1,0,0,1};

    queue<pair<pair<string, int>, pair<int, int>>> q;
    unordered_set<string> myset;
    q.push({{current, 0}, {r,c}});
    myset.insert(current);
    pair<string, int> leftNode;
    pair<int, int> rightNode;

    int nr, nc;

    while (!q.empty())
    {
        pair<pair<string, int>, pair<int, int>> nodeGeneral = q.front();
        q.pop();
        leftNode = nodeGeneral.first;
        rightNode = nodeGeneral.second;
        current = leftNode.first;
        string tmpString = current;
        r = rightNode.first;
        c = rightNode.second;

        if (current == "012345678") return leftNode.second;

        for (int i = 0; i < 4; i++)
        {
            current = tmpString;
            nr = r + dy[i];
            nc = c + dx[i];

            if (nr > -1 && nr < 3 && nc > -1 && nc < 3)
            {
                swap(current[3 * nr + nc], current[3 * r + c]);

                if (!myset.count(current))
                {
                    q.push({{current, leftNode.second + 1}, {nr, nc}});
                    myset.insert(current);
                }
            }
        }
    }

    return -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    std::cout << solve(matrix);

    return 0;
}