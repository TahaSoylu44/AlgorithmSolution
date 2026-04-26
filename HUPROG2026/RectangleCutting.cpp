#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(int length, int width, int hamle)
{
    if (length == width) return hamle;
    if (length == 0) return hamle;
    if (length == 1) return hamle + width - 1;

    if (width % length == 0) hamle += (width / length) - 1;
    else hamle += (width / length);

    return solve(width % length, length, hamle);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a < b) std::cout << solve(a, b, 0);
    else std::cout << solve(b, a, 0);
    
    return 0;
}