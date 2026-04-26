#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isPossible(int k, int n, int m, int value)
{
    if (m * (k - value) >= (n - value)) return true;
    else return false;
}

int findMax(int k, int n, int m)
{
    if ((k * m) < n) return -1;

    int left = 0;
    int right = k;
    int mid;

    while (left <= right)
    {
        if (left == ((left + right) / 2))
        {

            if (isPossible(k, n, m, left + 1)) return left + 1;
            else return left;
        }

        mid = (left + right) / 2;

        if (isPossible(k, n, m, mid)) left = mid;
        else right = mid - 1;
    }

    return left;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    std::cout << findMax(4, 20, 7) << '\n';
    
    return 0;
}