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

vector<bool> isPrime(1e5 + 1, true);

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int a,b;
    cin >> a >> b;
    int i;

    if (min(a,b) & 1) i = min(a,b);
    else i = min(a,b) - 1;

    for (; i >= 2; i -= 2)
    {
        if (isPrime[i])
        {
            int mod1 = a % i;
            int mod2 = b % i;

            if (mod1 == mod2) 
            {
                std::cout << i - mod1 << '\n';
                break;
            }
        }
    }
    
    return 0;
}