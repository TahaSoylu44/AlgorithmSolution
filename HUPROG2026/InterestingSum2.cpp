#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(int n)
{
    int num1 = n % 10;
    n /= 10;
    int num2 = n % 10;
    int num3 = n / 10;

    int maximum, mid, minimum;

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            maximum = num1;

            if (num2 > num3)
            {
                mid = num2;
                minimum = num3;
            }
            else
            {
                mid = num3;
                minimum = num2;
            }
        }
        else
        {
            maximum = num3;
            mid = num1;
            minimum = num2;
        }
    }
    else
    {
        if (num2 > num3)
        {
            maximum = num2;

            if (num1 > num3)
            {
                mid = num1;
                minimum = num3;
            }
            else
            {
                mid = num3;
                minimum = num1;
            }
        }
        else
        {
            maximum = num3;
            mid = num2;
            minimum = num1;
        } 
    }

    if (minimum == 0 && mid == 0) return 200 * maximum;
    if (minimum == 0) return 101 * maximum + 110 * mid;
    else return 101 * maximum + 20 * mid + 101 * minimum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    std::cout << solve(n);
    
    return 0;
}