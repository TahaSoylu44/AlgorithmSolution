#include <iostream>
#include <queue>

using namespace std;

void solve(priority_queue<long long>& pq, long long k)
{
    while (k > 0)
    {
        long long maximum = pq.top();
        pq.pop();
        maximum /= 2;
        k--;
        pq.push(maximum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long numOfItems;
    long long discountNumber;

    cin >> numOfItems >> discountNumber;

    priority_queue<long long> pq;

    for (long long i = 0; i < numOfItems; i++)
    {
        long long x;
        cin >> x;
        pq.push(x);
    }

    solve(pq, discountNumber);

    long long total = 0;

    while (!pq.empty())
    {
        total += pq.top();
        pq.pop();
    }
    
    std::cout << total;

    return 0;
}