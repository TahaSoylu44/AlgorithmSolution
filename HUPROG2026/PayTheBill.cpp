#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(int n)
{
    bool kusurat;

    if (n % 10 == 0) kusurat = false;
    else kusurat = true;

    if (kusurat)
    {
        n += (n/10);
        return n + 1;
    }
    else return (n + (n / 10));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int price;
    cin >> price;
    std::cout << solve(price);
    
    return 0;
}