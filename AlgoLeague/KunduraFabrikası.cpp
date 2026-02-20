#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int K = 1e9 + 7;

int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;

    return (b, a % b);
}

int fastExp(int A, int B, int K)
{
    if (B == 0 && A == 0) return -1;
    if (A == 0) return 0;
    if (B == 0) return 1;

    if (B % 2) return (fastExp(A, B - 1, K) * A) % K;
    else return (fastExp(A, B/2, K) * fastExp(A, B/2, K)) % K;
}

void sieve(vector<bool>& primeArray, int maximum)
{
    primeArray[1] = false;
    
    for (int i = 2; i <= maximum; i++)
    {
        if (!primeArray[i]) continue;

        for (int j = i * i; j <= maximum; j += i) primeArray[j] = false;
    }   
}

int stringHandle(string s, vector<int>& primeNumbers)
{
    int sum = 0;
    int index = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        int number = s[i] - '0';
        sum += fastExp(primeNumbers[index], number, K) % K;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    vector<bool> primeArray(size + 1);
    sieve(primeArray, size);

    vector<int> primeNumbers;

    int counter = 0;
    int index = 1;

    while (counter != size)
    {
        if (primeArray[index])
        {
            primeNumbers.push_back(index);
            counter++;
        }
        index++;
    }

    vector<int> stringValues;

    for (int i = 0; i < size; i++)
    {
        string s;
        cin >> s;
        stringValues.push_back(stringHandle(s, primeNumbers));
    }

    int ebob = gcd(stringValues[0], stringValues[1]);

    for (int i = 2; i < size; i++) ebob = gcd(ebob, stringValues[i]);

    int total = 0;

    for (int num : stringValues) total = (total + (num / ebob)) % K;

    std::cout << total % K;
    
    return 0;
}