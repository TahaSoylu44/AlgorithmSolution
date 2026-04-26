#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int binary_search(int n)
{
    int counter = 0;

    while (n != 0)
    {
        n /= 2;
        counter++;
    }
    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    std::cout << min(binary_search(n), k);
    
    return 0;
}