#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isPossible(vector<int>& array, int change_1, int change_2, int len)
{   
    int numOf1 = 0;
    int numOf2 = 0;

    for (int j = 0; j < len; j++)
    {
        if (array[j] == 1) numOf1++;
        else if (array[j] == 2) numOf2++;
    }

    if (change_1 >= numOf1 && change_2 >= numOf2) return true;

    for (int i = 1; i <= array.size() - len; i++)
    {
        if (array[i - 1] == 1) numOf1--;
        else if (array[i - 1] == 2) numOf2--;

        if (array[i - 1 + len] == 1) numOf1++;
        else if (array[i - 1 + len] == 2) numOf2++;

        if (change_1 >= numOf1 && change_2 >= numOf2) return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfCakes, change_1, change_2;
    cin >> numOfCakes >> change_1 >> change_2;

    vector<int> array(numOfCakes);

    for (int i = 0; i < numOfCakes; i++) cin >> array[i];
    
    int left = 0;
    int right = numOfCakes;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (isPossible(array, change_1, change_2, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    std::cout << ans;
    
    return 0;
}