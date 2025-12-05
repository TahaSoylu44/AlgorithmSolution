#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

bool helper(int n, vector<int>& cache)
{
    counter++;
    if (n == 1) return false;

    if (cache[n] == -1)
    {
        if (n % 2 == 0)
        {
            bool opt1 = !(helper(n/2, cache));
            bool opt2 = !(helper(n - 1, cache));
            cache[n] = opt1 || opt2;
            counter--;
        }
        else
        {
            bool opt = !(helper(n - 1, cache));
            cache[n] = opt;
        } 
    }
    return cache[n];
}

bool firtsWins(int n)
{
    vector<int> cache(n + 1, -1);

    return helper(n, cache);
}

int main() {
    int number;
    cin >> number;

    if (firtsWins(number))
    {
        std::cout << "Ayla " << counter << std::endl;
    }
    else
    {
        std::cout << "Boran " << counter << std::endl;
    }
    
    return 0;
}