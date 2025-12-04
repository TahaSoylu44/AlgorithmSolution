#include <iostream>
#include <cmath>

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int squareroot = sqrt(n);

    for (int i = 3; i <= squareroot + 1; i += 2)
    {
        if (n % i == 0) return false;
    } 
    return true;
}


int main() {

    long long result = 0;

    for (int i = 1999999; i > 2; i = i - 2)
    {
        if (isPrime(i)) result += i;
    }

    std::cout << result + 2 << std::endl;

    return 0;
}