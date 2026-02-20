#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

// int howmanyBig(vector<int>& array, int left, int right, int element)
// {
//     int counter = 0;
    
//     for (int i = left; i < right; i++)
//     {
//         if (array[i] > element) counter++;
//     }
//     return counter;
// }

// int howmanySmall(vector<int>& array, int left, int right, int element)
// {
//     int counter = 0;

//     for (int i = left + 1; i <= right; i++)
//     {
//         if (array[i] < element) counter++;
//     }
//     return counter;
// }

int solve(vector<int>& array, int k)
{
    int counter = 0;
    int left = 0;
    int hak = 0;
    int right = 0;
    int howmany;

    vector<int> v;

    for (; right < array.size(); right++)
    {
        // hak += howmanyBig(array, left, right, array[right]);
        howmany = v.end() - upper_bound(v.begin(), v.end(), array[right]) + 1;
        hak += howmany;

        while (hak > k)
        {
            // hak -= howmanySmall(array, left, right, array[left]);
            auto it = lower_bound(v.begin(), v.end(), array[left]);
            hak -= array.size() - (v.end() - lower_bound(v.begin(), v.end(), array[left]));

            if(*it == array[left]) hak--;
            
            left++;
        }

        counter += right - left + 1;
        v.push_back(array[right]);
        sort(v.begin(), v.end());
    }
    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, k;
    cin >> size >> k;
    vector<int> array(size);

    for (int i = 0; i < size; i++) cin >> array[i];
    std::cout << solve(array, k);
    
    return 0;
}