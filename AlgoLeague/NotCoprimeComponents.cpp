#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<bool> isPrime(1e6 + 1, true);
vector<int> howManyPrime(1e6 + 2);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= 1e6; i += 2) isPrime[i] = false;

    for (int i = 3; i * i <= 1e6; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1e6; j += (i * 2))
            {
                isPrime[j] = false;
            }
        }
    }
}

int solve(int n)
{
    if (n < 4) return 1;
    int prime = howManyPrime[n] - howManyPrime[n / 2];
    return n - prime - 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    howManyPrime[0] = howManyPrime[1] = 0;

    for (int i = 2; i <= 1e6; i++)
    {
        if (isPrime[i]) howManyPrime[i] = howManyPrime[i - 1] + 1;
        else howManyPrime[i] = howManyPrime[i - 1];
    }

    int n, a;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        std::cout << solve(a) << '\n';
    }
    
    return 0;
}