#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void print(vector<int>& array)
{
    for (int num : array) std::cout << num << " ";
    if (array.empty()) std::cout << -1;
    std::cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, s, num, den, k;
    cin >> t;
    vector<int> hearts;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> hearts;

        for (int j = 0; j <= 61; j++)
        {
            num = n + (1LL << j);
            den = (1LL << (j + 1)) - 1;

            if (num % den == 0)
            {
                s = num / den;

                if (s >= 1)
                {
                    k = n - s + 1;
                    if (k >= 1 && k <= n) hearts.push_back(k);
                }
            }
        }

        sort(hearts.begin(), hearts.end());
        print(hearts);
    }
    
    return 0;
}