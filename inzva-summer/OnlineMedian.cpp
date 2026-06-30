#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> small_pq;
    priority_queue<int> bigger_pq;

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        small_pq.push(num);

        if (small_pq.size() > bigger_pq.size() + 1) // first condition
        {
            bigger_pq.push(-1 * small_pq.top());
            small_pq.pop();
        }

        if (!bigger_pq.empty() && small_pq.top() > -1 * bigger_pq.top())    // second condition
        {
            bigger_pq.push(-1 * small_pq.top());
            small_pq.pop();
        }

        if (!bigger_pq.empty() && bigger_pq.size() > small_pq.size())   // third condition
        {
            small_pq.push(-1 * bigger_pq.top());
            bigger_pq.pop();
        }

        //* Median
        if (small_pq.size() == bigger_pq.size()) std::cout << (small_pq.top() + (bigger_pq.top() * -1)) / 2 << '\n';
        else std::cout << small_pq.top() << '\n';
    }
    
    return 0;
}