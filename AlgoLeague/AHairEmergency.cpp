#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int formula(int x, int L, int C) {return x * (L - C * x);}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, L, C, left, right, opt1, opt2; cin >> T;

    while (T--)
    {
        cin >> L >> C;
        left = L / (2 * C);
        right = left + 1;

        opt1 = formula(left, L, C);
        opt2 = formula(right, L, C);

        std::cout << max(opt1,opt2) << '\n';
    }
    
    return 0;
}