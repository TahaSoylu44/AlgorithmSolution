#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(int n)
{
    double total = 0;

    for (int i = 1; i <= n; i++) total += log10(i);
    return floor(total) + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    std::cout << solve(n);
    
    return 0;
}