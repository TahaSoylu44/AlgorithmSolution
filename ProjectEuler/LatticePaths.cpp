#include <iostream>
#include <vector>

using namespace std;

long long helper(int n, vector<long long>& dp)
{
    if (n < 0) return -1;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];

    return dp[n] = n * helper(n - 1, dp);
}

void func()
{
    vector<long long> dp(41, -1);
    dp[0] = dp[1] = 1;

    long long twenty = helper(20, dp);
    long long fourty = helper(40, dp);

    std::cout << fourty << '\n';
    std::cout << twenty << '\n';
}

void myfunc()
{
    long long result = 1;
    int divider = 1;
    long long keep = 1;

    for (int i = 1; i < 41; i++)
    {
        result *= i;

        if (i <= 20)
        {
            keep *= i;

            if (result % keep == 0)
            {
                result /= keep;
                keep = 1;
            }
        }
        else
        {
            keep *= divider;

            if (result % keep == 0)
            {
                result /= keep;
                keep = 1;
            } 
            divider++;
        }
    }
    std::cout << result;
}

int main() {

    myfunc();
    
    return 0;
}