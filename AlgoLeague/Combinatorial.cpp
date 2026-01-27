#include <bits/stdc++.h>

using namespace std;

const long long int p = 1e9 + 7;    // MOD

long long int factorial(long long int n)
{
    if (n == 0 || n == 1) return 1;
    
    long long int result = 1;

    for (long long int i = 2; i <= n; i++) result = (result * i) % p;   // iterative factorail calculation
    return result;
}

long long int fastExp(long long int A, long long int B)
{
    if (B == 0 && A == 0) return -1;
    if (A == 0) return 0;
    if (B == 0) return 1;

    if (B % 2) return (fastExp(A, B - 1) * A) % p;
    else
    {
        long long int a = fastExp(A, B/2);
        return (a * a) % p;
    }
}

long long int combination(long long int A, long long int B)
{
    long long int x = factorial(A);
    long long int y = fastExp(factorial(B), p - 2);
    long long int z = fastExp(factorial(A - B), p - 2);

    long long int result = (x * y) % p; // her çarpım için modül alma
    result = (result * z) % p;
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int A, B;
    cin >> A >> B;

    std::cout << combination(A, B);
    
    return 0;
}