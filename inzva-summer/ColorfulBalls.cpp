#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isAppropriate(vector<int>& v, int h, int k)
{
    if (h == 0) return true;
    int total = 0;
    int counter = 0;
    int effective_value;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        effective_value = min(h, v[i]);
        total += effective_value;
        counter++;

        if (counter >= k)
        {
            if (total / h >= k) return true;
        }
    }
    return false;
}

int solve(vector<int>& v, int k, int total)
{
    int left = 0;
    int right = total / k;
    int ans, mid;
    vector<int> array;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (isAppropriate(v, mid, k))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, num;
    cin >> n >> k;
    int total = 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
        total += num;
    }
    sort(v.begin(), v.end());

    std::cout << solve(v, k, total);
    
    return 0;
}