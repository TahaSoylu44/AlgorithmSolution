#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int MOD  = 1e9 + 7;

void solve(vector<int>& array, vector<vector<int>>& dp)
{
    int numOfnumbers = 0;

    for (int num : array)
    {
        //
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    vector<int> array(n);

    for (int i = 0; i < n; i++) cin >> array[i];
    sort(array.begin(), array.end());
    
    return 0;
}