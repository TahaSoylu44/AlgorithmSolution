#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    int x, y;
    pair<int, int> bidirectional;

    cin >> N >> M;  

    priority_queue<pair<int, int>> pairs;
    set<pair<int, int>> myset;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        if (myset.count({x,y})) continue;

        myset.insert({x,y});

        if (myset.count({y,x}))
        {
            if (x < y) pairs.push({-x, -y});
            else if (x > y) pairs.push({-y, -x});
        }
    }

    std::cout << pairs.size() << '\n';

    while (!pairs.empty())
    {
        bidirectional = pairs.top();
        pairs.pop();
        std::cout << -1 * bidirectional.first << " ";
        std::cout << -1 * bidirectional.second << '\n';
    }
    
    return 0;
}