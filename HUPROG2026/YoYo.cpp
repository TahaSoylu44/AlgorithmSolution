#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(double l, double k)
{
    int counter = 0;

    while (l > 1)
    {
        l /= k;
        if (l > 1) counter++;
    }

    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double l, k;
    cin >> l >> k;
    std::cout << solve(l, k);
    
    return 0;
}