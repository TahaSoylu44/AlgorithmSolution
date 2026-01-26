#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long size;
    cin >> size;
    long long quantity = 0;
    long long number;
    long long total = 0;

    priority_queue<long long> pq;

    for (long long i = 0; i < size; i++)
    {
        cin >> number;
        total += number;
        quantity++;
        pq.push(-1 * number);

        while (total < 0)
        {
            if (pq.empty())
            {
                quantity = 0;
                break;
            }

            total += pq.top();
            pq.pop();
            quantity--;
        }
    }

    std::cout << quantity;
    
    return 0;
}