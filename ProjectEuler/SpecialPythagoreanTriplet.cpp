#include <iostream>

long long findSolution()
{
    long c;
    long s;

    for (int a = 999; a > 0; a--)
    {
        for (int b = 1000 - a - 1; b > 0; b--)
        {
            c = 1000 - a - b;

            s = a*a + b*b;

            if (s == c*c)
            {
                return c;
            }
        }
    }
    return -1;
}

int main() {

    std::cout << findSolution() << std::endl;
    
    return 0;
}