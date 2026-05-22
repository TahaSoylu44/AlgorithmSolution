#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int gcd(int a, int b)
{
    if (a == 0 && b == 0) return -1;
    if (a == 0) return b;
    if (b == 0) return a;

    return gcd(b, a % b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    std::cout << gcd(a,b) << '\n';
    return 0;
}