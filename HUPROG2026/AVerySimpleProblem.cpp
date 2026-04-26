#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int MOD;

int fastExp(int a, int b)
{
    if (a == 0) return 0;
    if (b == 0) return 1;

    if (b % 2) return (a * fastExp(a, b - 1)) % MOD;
    else
    {
        int half = fastExp(a, b/2) % MOD;
        return (half * half) % MOD;
    }
}

int solve(int N, int x)
{
    int total = 0;

    for (int k = 1; k <= N; k++)
    {
        int a = fastExp(k, x);
        int b = fastExp(x, k);
        int c = (a * b) % MOD;
        total = (total + c) % MOD;
    }

    return total;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;

    while (true)
    {
        cin >> N >> x >> MOD;
        if (N < 0) break;
        std::cout << solve(N, x) << '\n';
    }
    
    return 0;
}