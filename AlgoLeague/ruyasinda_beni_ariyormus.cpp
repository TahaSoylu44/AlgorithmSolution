#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        n %= 6;
        if (n > 1) cout << "Yunus" << '\n';
        else cout << "Mustafa" << '\n';
    }

	return 0;
}