#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<long long>& v)
{
    priority_queue<long long> pq;
    long long number;
    long long counter = 0;

    for (long long i = 0; i < v.size(); i++)
    {
        number = v[i];

        if (number == 0)    // hero card
        {
            if (pq.empty()) continue;

            counter += pq.top();
            pq.pop();
        }
        else    // bonus card
        {
            pq.push(number);
        }
    }

    std::cout << counter << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long times;
    cin >> times;

    for (long long i = 0; i < times; i++)
    {
        long long size;
        cin >> size;

        vector<long long> v(size, -1);

        for (long long j = 0; j < size; j++) cin >> v[j];
        solve(v);
    }
    
    return 0;
}