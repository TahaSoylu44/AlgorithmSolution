#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int twoPointers(vector<int>& array, int change_1, int change_2)
{
    int left = 0;
    int maximum = 0;

    for (int right = 0; right < array.size(); right++)
    {
        if (array[right] == 1) change_1--;
        else if (array[right] == 2) change_2--;

        while (change_1 < 0)
        {
            if (array[left] == 1) change_1++;
            else if (array[left] == 2) change_2++;
            left++;
        }

        while (change_2 < 0)
        {
            if (array[left] == 1) change_1++;
            else if (array[left] == 2) change_2++;
            left++;
        }

        maximum = max(maximum, right - left + 1);
    }
    return maximum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, change_1, change_2;
    cin >> size >> change_1 >> change_2;

    vector<int> array(size);

    for (int i = 0; i < size; i++) cin >> array[i];

    int ans = twoPointers(array, change_1, change_2);

    if (ans < 0) std::cout << 0;
    else std::cout << ans;
    
    return 0;
}