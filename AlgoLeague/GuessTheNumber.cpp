#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    string message = "";

    int left = 1;
    int right = N;
    int ans = (left + right) / 2;
    std::cout << ans << endl;
    cin >> message;

    while (message != "Congratulations")
    {
        if (message == "Low") left = ans + 1;
        else right = ans;
        ans = (left + right) / 2;
        std::cout << ans << endl;
        cin >> message;
    }
    
    return 0;
}