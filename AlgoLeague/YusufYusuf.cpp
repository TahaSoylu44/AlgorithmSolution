#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isPossible(vector<int>& array, int len, int minimum)
{
    if (array.size() < len) return false;
    int counter = 0;
    int now = 0;

    for (int i = 0; i < len; i++) now += array[i];
    counter += now;
    if (counter >= minimum) return true;

    for (int i = 1; i <= array.size() - len; i++)
    {
        now = now - array[i - 1];
        now = now + array[i + len - 1];
        counter += now;
        if (counter >= minimum) return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, minimum;
    cin >> size >> minimum;

    vector<int> array(size);
    for (int i = 0; i < size; i++) cin >> array[i];
    
    int left = 1;
    int right = size;
    int mid;
    int ans = size;

    while (left < right)
    {
        mid = (left + right) / 2;

        if (isPossible(array, mid, minimum))
        {
            ans = mid;
            right = mid;
        }
        else left = mid + 1;
    }

    std::cout << ans;
    
    return 0;
}