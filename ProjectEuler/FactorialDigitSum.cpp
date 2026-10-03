#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> product(int n)
{
    vector<int> array = {1};
    int result;
    int remainder = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            result = array[j] * i;
            result += remainder;
            array[j] = result % 10;
            remainder = result / 10;
        }

        while (remainder > 10)
        {
            array.push_back(remainder % 10);
            remainder /= 10;
        }

        if (remainder != 0) 
        {
            array.push_back(remainder);
            remainder = 0;
        }
    }

    return array;
}

void print(vector<int>& array)
{
    if (array.empty()) return;

    for (int num : array) std::cout << num << " ";
    std::cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> array = product(100);
    int result = 0;
    for (int num : array) result += num;
    std::cout << result << '\n';
    
    return 0;
}