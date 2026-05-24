#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int hipo(int a, int b)
{
    return sqrt((a * a) + (b * b));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    int a, b, c;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        c = hipo(a, b);
        pq.push(c);
    }

    int count = 0;

    while (!pq.empty())
    {
        int mypair = pq.top();
        pq.pop();
        count++;
        m -= mypair;
        if (m <= 0) break;
    }

    if (m <= 0) std::cout << count << '\n';
    else std::cout << -1 << '\n';
    
    return 0;
}