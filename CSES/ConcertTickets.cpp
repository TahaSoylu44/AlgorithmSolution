#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> ms;

    int ticket;
    int money;

    for (int i = 0; i < n; i++)
    {
        cin >> ticket;
        ms.insert(ticket);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> money;
        auto it = ms.upper_bound(money);

        if (it == ms.begin())  std::cout << -1 << '\n';

        else
        {
            it--;
            std::cout << *it << '\n';
            ms.erase(it);
        }
    }
    
    return 0;
}