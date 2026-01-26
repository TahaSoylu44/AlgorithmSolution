#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long helper(vector<long long>& array)
{
    long long total;
    long long cost = 0;

    for (long long i = 0; i <= array.size() - 3; i++)
    {
        total = array[i] + array[i + 1] + array[i + 2];

        if (total < 0)
        {
            array[i + 2] += abs(total);
            cost += abs(total);
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long size;
    cin >> size;

    vector<long long> array(size);

    for (long long i = 0; i < size; i++) cin >> array[i];

    std::cout << helper(array);
    
    return 0;
}