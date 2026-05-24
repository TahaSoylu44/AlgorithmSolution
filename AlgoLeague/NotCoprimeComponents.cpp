#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<bool> isPrime(1e6, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i < 501; i += 2) isPrime[i] = false;

    for (int i = 3; i * i < 501; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < 501; j += (i * 2))
            {
                isPrime[j] = false;
            }
        }
    }
}

int solve(int n)
{
    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int j;
        if (i % 2) j = i;
        else j = i - 1;

        for (; j >= 3; j -= 2)
        {
            if (isPrime[j])
            {
                if (i % j == 0)
                {
                    v[j]++;
                }
            }
        }
    }

    int max_num = 0;
    for (int num : v) max_num = max(max_num, num);
    return max_num;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    int n, a;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        std::cout << solve(a) << '\n';
    }
    
    return 0;
}