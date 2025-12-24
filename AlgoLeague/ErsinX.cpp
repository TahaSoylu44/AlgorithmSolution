#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long MOD = 998244353;

long long multiply(long long a, long long b)
{
    return (a * b) % MOD;
}

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1) res = multiply(res, base);
        
        base = multiply(base, base);
        
        exp /= 2;
    }
    return res;
}

long long factoriel(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result = multiply(result, i);
    }
    return result;
}

int numOfPaths(vector<int>& coordinates)
{
    long long sum = accumulate(coordinates.begin(), coordinates.end(), 0LL);
    
    long long result = factoriel(sum);

    for (int i = 0; i < coordinates.size(); i++)
    {
        long long inverse = power(factoriel(coordinates[i]), MOD - 2);
        
        result = multiply(result, inverse);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dim;
    if (!(cin >> dim)) return 0;

    vector<int> coordinates(dim);
    for (int i = 0; i < dim; i++) cin >> coordinates[i];

    cout << numOfPaths(coordinates);
    
    return 0;
}