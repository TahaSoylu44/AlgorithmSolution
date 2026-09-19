#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int rounds(int m, int n)
{
    return (2 * (max(m,n)) - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int m, n;

    for (int i = 0; i < T; i++)
    {
        cin >> m >> n;
        std::cout << rounds(m, n) << endl;
    }
    return 0;
}