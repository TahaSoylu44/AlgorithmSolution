#include <iostream>
#include <vector>

using namespace std;

long long arraySum(vector<int>& array)
{
    long long n = 0;
    for (int number : array) n+=number;
    return n;
}

void expectedValue(vector<int>& array)
{
    int size = array.size();
    long long sumArray = arraySum(array);
    long long result;

    for (int i = size - 1; i >= 1; i--)
    {
        result = sumArray * i / size;
        std::cout << result << " ";
    }
    std::cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int repetition;
    cin >> repetition;

    for (int i = 0; i < repetition; i++)
    {
        int size;
        cin >> size;

        vector<int> array(size);
        for (int i = 0; i < size; i++) cin >> array[i];

        expectedValue(array);
        std::cout << '\n';
    }
    
    return 0;
}