#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool is_hindex(vector<int>& array, int h) {
    if (h == 0) return true;
    return (array[array.size() - h] >= h);
}

int solve(vector<int>& array)
{
    int l = 0;
    int r = array.size();
    int mid;
    int ans = 0;

    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (is_hindex(array, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<int> array(m);
    for (int i = 0; i < m; i++) cin >> array[i];
    sort(array.begin(), array.end());

    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        array.push_back(num);
        std::cout << solve(array) << '\n';
    }
    
    return 0;
}