#include <iostream>
#include <vector>

using namespace std;

vector<string> small = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

vector<string> big = {"","", "twenty", "thirty", "forty", "fifty", "sixty", "seventy","eighty", "ninety"};

int countLetters(int n)
{
    if (n < 20) return small[n].size();

    int hundred = n / 100;
    int bigOne = (n % 100) / 10;
    int smallOne;

    if ((n % 100) <= 19 && (n % 100) >= 10) smallOne = n % 20;
    else smallOne = n % 10;

    if (n % 100 == 0) return small[hundred].size() + 7;

    if (hundred > 0) return  small[hundred].size() + 10 + big[bigOne].size() + small[smallOne].size();
    
    return big[bigOne].size() + small[smallOne].size();
}

int main() {

    std::cout << countLetters(101) << '\n';

    long long t = 0;

    for (int i = 1; i < 1000; i++) t += countLetters(i);

    std::cout << t;
    
    return 0;
}