#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, k;
    cin >> size >> k;

    vector<int> dp(k + 1, -1);

    for (int i = 0; i < k; i++) dp[i] = 2;
    dp[k] = 1;
    int a, b;
    b = 2;
    for (int r = size - 2; r >= 0; r--) {     
        a = b;
        b = dp[0];
        for (int c = 0; c < k; c++) {
            dp[c] = (b + dp[c + 1]) % MOD;
        }

        if (r + 2 < size) dp[k] = a % MOD;
        else dp[k] = 1;
    }

    std::cout << dp[0] % MOD;
    
    return 0;
}