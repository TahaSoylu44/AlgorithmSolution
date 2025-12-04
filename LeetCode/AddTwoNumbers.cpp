#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        char l1 = s[0];
        char l2;
        int i1;
        int i2;
        int result = 0;
        int repeated = 1;
        int repatedValue;
        bool isAdded = false;
        
        for (int i = 1; i < s.size(); i++)
        {
            l2 = s[i];

            switch (l1)
            {
            case 'I': i1 = 1; break;
            case 'V': i1 = 5; break;
            case 'X': i1 = 10; break;
            case 'L': i1 = 50; break;
            case 'C': i1 = 100; break;
            case 'D': i1 = 500; break;
            case 'M': i1 = 1000; break;
            default: break;
            }

            switch (l2)
            {
            case 'I': i2 = 1; break;
            case 'V': i2 = 5; break;
            case 'X': i2 = 10; break;
            case 'L': i2 = 50; break;
            case 'C': i2 = 100; break;
            case 'D': i2 = 500; break;
            case 'M': i2 = 1000; break;
            default: break;
            }

            if (i2 > i1)
            {
                if (repeated != 1)
                {
                    result -= repeated * repatedValue;
                    repeated = 1;
                    repatedValue = 0;
                }
                else
                {
                    result -= i1;
                    result += i2;
                    isAdded = true;
                }
            }
            else if(i1 > i2)
            {
                if (repeated != 1)
                {
                    result += repeated * repatedValue;
                    repeated = 1;
                    repatedValue = 0;
                }
                else
                {
                    if (!isAdded)
                    {
                        result += i1;
                    }
                    else
                    {
                        isAdded = false;
                    }
                }
                if (i == s.size() - 1)
                {
                    result += i2;
                }   
            }
            else
            {
                repeated++;
                repatedValue = i1;
            }

            l1 = l2;
        }

        if (repeated != 1)
        {
            result += repeated * repatedValue;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int answer = solution.romanToInt("MCMXCVI");
    std::cout << answer << std::endl;
    return 0;
}