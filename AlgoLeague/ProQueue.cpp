#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;

    int times;
    cin >> times;

    for (int z = 0; z < times; z++)
    {
        vector<int> v(2, -1);

        cin >> v[0];

        if (v[0] == 1) cin >> v[1];

        if (v[0] == 1)  // add
        {
            pq.push(v[1]);
        }
        else if (v[0] == 2) // max
        {
            if (pq.empty()) std::cout << -1 << '\n';
            else
            {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    
    return 0;
}