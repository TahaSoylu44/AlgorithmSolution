#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int sum_digits(int n)
{
    int sum = 0;

    while (n != 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int solve(int n, int k)
{
    int left = 1;
    int right = n - 1;
    int ans = 0;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if ((mid - k) >= sum_digits(mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int iter, n, k;
    cin >> iter;
    int result;

    for (int i = 0; i < iter; i++)
    {
        cin >> n >> k;
        result = solve(n, k);

        if (result == 0) std::cout << 0 << '\n';
        else std::cout << n - result + 1 << '\n';
    }

    return 0;
}