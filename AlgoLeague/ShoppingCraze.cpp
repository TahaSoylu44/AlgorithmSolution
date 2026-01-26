#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long numOfItems;
    cin >> numOfItems;

    vector<long long> presum(numOfItems + 1, -1);
    presum[0] = 0;

    for (long long i = 1; i <= numOfItems; i++)
    {
        long long x;
        cin >> x;

        presum[i] = presum[i - 1] + x;
    }

    long long times;
    cin >> times;

    for (long long i = 0; i < times; i++)
    {
        long long bound;
        cin >> bound;

        auto it = lower_bound(presum.begin(), presum.end(), bound);

        std::cout << it - presum.begin() - 1 << '\n';
    }
    
    return 0;
}