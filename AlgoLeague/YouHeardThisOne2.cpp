#include <iostream>

using namespace std;

long long logaritmic(long long n)
{
    long long counter = 0;

    while (n != 0)
    {
        n /= 2;
        counter++;
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long minimum, maximum;

    cin >> minimum >> maximum;

    std::cout << logaritmic(maximum - minimum + 1);
    
    return 0;
}