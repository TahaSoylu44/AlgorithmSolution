#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int fast_exp(int a, int b, int p)
{
    if (a == 0 && b == 0) return -1;
    if (a == 0) return 0;
    if (b == 0) return 1;

    a = a % p;

    if (b & 1) return (a * fast_exp(a, b - 1, p)) % p;
    else
    {
        int half = fast_exp(a, b >> 1, p);
        return (half * half) % p;
    }
}

int mod_inverse(int b, int p)
{
    return fast_exp(b, p - 2, p);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,p;
    cin >> a >> b >> p;
    std::cout << "a/b: ";
    std::cout << (a * mod_inverse(b, p)) % p << '\n';
    return 0;
}