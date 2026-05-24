#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    int s,f;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> f;
        pq.push({-f,-s});
    }

    int counter = 0;
    int oldf = 0;

    while (!pq.empty())
    {
        pair<int,int> node = pq.top();
        pq.pop();
        int s = node.second * -1;
        int f = node.first * -1;

        if (s >= oldf)
        {
            counter++;
            oldf = f;
        }
    }

    std::cout << counter << '\n';
    
    return 0;
}