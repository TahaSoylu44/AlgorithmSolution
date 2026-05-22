#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<bool> isPrime(501, true);

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
    int num;
    cin >> num;

    if (isPrime[num]) std::cout << "PRIME" << '\n';
    else std::cout << "NOT PRIME" << '\n';
    
    return 0;
}