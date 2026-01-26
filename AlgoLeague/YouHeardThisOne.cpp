#include <iostream>
#include <algorithm>

using namespace std;

long long helper(long long minimum, long long maximum)
{
    long long counter = 0;
    long long anotherCounter = 0;
    long long guess = (minimum + maximum) / 2;
    long long newGuess;

    while (1)
    {
        newGuess = (guess + maximum) / 2;
        counter++;

        if (newGuess == guess) break;
        else guess = newGuess;
    }

    guess = (minimum + maximum) / 2;

    while (1)
    {
        newGuess = (guess + minimum) / 2;
        anotherCounter++;

        if (newGuess == guess) break;
        else guess = newGuess;
    }

    return min(counter, anotherCounter);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long minimum, maximum;

    cin >> minimum >> maximum;

    std::cout << helper(minimum,maximum);
    
    return 0;
}