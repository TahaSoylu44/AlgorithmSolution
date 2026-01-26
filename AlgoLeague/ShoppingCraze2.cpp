#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<long long>& ms, long long bound)
{
    long long quantity = 0;
    long long total = 0;

    for (long long num : ms)
    {
        total += num;
        quantity++;

        if (total >= bound) return (quantity - 1);
    }
    return quantity;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long numOfItems;
    cin >> numOfItems;

    vector<long long> ms;
    long long total = 0;

    for (long long i = 0; i < numOfItems; i++)
    {
        long long x;
        cin >> x;
        ms.push_back(x);
    }

    long long times;
    cin >> times;

    for (long long i = 0; i < times; i++)
    {
        long long bound;
        cin >> bound;

        std::cout << solve(ms, bound) << '\n';
    }
    
    return 0;
}