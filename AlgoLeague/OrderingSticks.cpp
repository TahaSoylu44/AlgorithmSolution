#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    if (N == 1)
    {
        std::cout << 1;
        return 0;
    }

    vector<int> result;
    int left = 1;
    int right = N;
    bool added = 0;

    while (result.size() != N)
    {
        if (added)
        {
            result.push_back(left);
            left++;
            added = 0;
        }
        else
        {
            result.push_back(right);
            right--;
            added = 1;
        }
    }

    for (int i = N - 1; i >= 0; i--) std::cout << result[i] << " ";
    std::cout << '\n';

    result.clear();
    left = 1;
    right = N;
    added = 1;

    while (result.size() != N)
    {
        if (added)
        {
            result.push_back(left);
            left++;
            added = 0;
        }
        else
        {
            result.push_back(right);
            right--;
            added = 1;
        }
    }

    for (int i = N -1; i >= 0; i--) std::cout << result[i] << " ";
    
    return 0;
}