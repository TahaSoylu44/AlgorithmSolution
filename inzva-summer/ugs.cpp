#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isValid(int trial, int x, int y)
{
    if (trial % x == 0) return false;
    if (trial % y == 0) return false;

    int max_num, min_num;

    if (y > x)
    {
        max_num = y;
        min_num = x;
    }
    else
    {
        max_num = x;
        min_num = y;
    }

    int quantitiy = trial / max_num;

    for (int i = 0; i <= quantitiy; i++)
    {
        if (((trial - i * max_num) % min_num) == 0) return false;
    }

    std::cout << "trial: " << trial << '\n';

    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> flowers(n);
    for (int i = 0; i < n; i++) cin >> flowers[i];

    int xort = flowers[0];

    for (int i = 1; i < n; i++) xort = xort ^ flowers[i];

    if (xort == 0)
    {
        std::cout << "Salih";
        return 0;
    }

    vector<int> need;

    for (int num : flowers) need.push_back(num - (num ^ xort));

    bool isAnyValid = false;

    for (int num : need)
    {
        if (num > 0)
        {
            if (isValid(num, x, y))
            {
                isAnyValid = true;
                break;
            }
        }
    }

    if (isAnyValid) std::cout << "Ahmet";
    else std::cout << "Salih";

    return 0;
}