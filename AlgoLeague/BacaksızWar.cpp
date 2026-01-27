#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isPossible(vector<int>& v, int numOfTroops, int x)
{
    int counter = 1;
    int last_position = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - last_position >= x)
        {
            counter++;
            last_position = v[i];
        }

        if (counter == numOfTroops) return true;
    }   
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int numOFLocations;
    int numOfTroops;

    cin >> numOFLocations >> numOfTroops;

    vector<int> v(numOFLocations);

    for (int i = 0; i < numOFLocations; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int right = v[numOFLocations - 1] - 1;
    int left = 0;
    int result = -1;

    while (result != left && result != right)
    {
        int mid = (left + right) / 2;

        if (isPossible(v, numOfTroops, mid)) left = mid;
        else right = mid - 1;

        if ((left + right) / 2 == mid)
        {
            if (isPossible(v, numOfTroops, right)) result = right;
            else result = left;
        }
    }

    std::cout << result;
    
    return 0;
}