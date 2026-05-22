#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int MOD = 1e9 + 7;

int fast(int a, int b)
{
    if (a == 0 && b == 0) return -1;
    if (a == 0) return 0;
    if (b == 0) return 1;

    a = a % MOD;

    if (b & 1) return (a * fast(a, b - 1)) % MOD;
    else
    {
        int half = fast(a, b >> 1);
        return (half * half) % MOD;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    std::cout << fast(a,b) << '\n';
    return 0;
}