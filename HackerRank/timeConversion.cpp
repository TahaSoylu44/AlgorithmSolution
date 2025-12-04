#include <iostream>

using namespace std;

string timeConversion(string s)
{
    bool isTwelve = false;
    string result = "00:00:00";

    if (s[0] == '1')
    {
        if (s[1] == '2')
        {
            isTwelve = true;
        }
    }
    
    if (s[8] == 'P')
    {
        if (!isTwelve)
        {
            int first = s[0] - '0';
            int second = s[1] - '0';
            int number = 10 * first + second;
            number += 12;
            first = number / 10;
            second = number % 10;
            char charFirst = first + '0';
            char charSecond = second + '0';
            s[0] = charFirst;
            s[1] = charSecond;
        }
    }
    else
    {
        if (isTwelve)
        {
            s[0] = '0';
            s[1] = '0';
        }
    } 

    for (int i = 0; i < result.size(); i++) result[i] = s[i];

    return result;
}



int main() {

    string s = "03:01:00PM";

    std::cout << timeConversion(s) << std::endl;
    
    return 0;
}