#include <iostream>
#include <vector>

using namespace std;

long long getValue(long long n)
{
    long long counter = 0;

    while (n != -1)
    {
        while (n % 2 == 0)
        {
            n /= 2;
            counter++;
        }

        if (n == 1) break;

        n = (3 * n + 1) / 2;
        counter += 2;
    } 
    return counter;
}

long long helper(long long n, vector<long long>& dp)
{
    if (n >= 1e6) return getValue(n);
    if (dp[n] != -1) return dp[n];

    if (n % 2) return dp[n] = (helper((3*n+1), dp)) + 1;
    else return dp[n] = (helper((n/2), dp)) + 1;
}

int getMax()
{
    vector<long long> dp(1e6, -1);
    dp[1] = 0;

    long long maxValue = 0;
    long long idx = 0;
    long long val;

    for (int i = 999999; i >= 2; i--)
    {
        val = helper(i, dp);

        if (val > maxValue)
        {
            maxValue = val;
            idx = i;
        }
    }
    return idx;
}

int main() {

    std::cout << getMax();
    
    return 0;
}