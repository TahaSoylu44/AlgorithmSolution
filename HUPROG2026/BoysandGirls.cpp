#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool adapted(unordered_map<int, int>& mymap, pair<int, int>& mypair, int right, int left)
{
    if (mymap.empty()) return true;
    if (mymap[mypair.first] == (right - left) || mymap[mypair.second] == (right - left)) return true;
    return false;
}

int solve(vector<pair<int, int>>& array)
{
    int left, right;
    left = right = 0;
    unordered_map<int, int> mymap;
    int max_length = 0;
    pair<int, int> mypair = {0,0};
    pair<int, int> leftPair = {0,0};

    for (; right < array.size(); right++)
    {
        mypair = array[right];

        while (!adapted(mymap, mypair, right, left))
        {
            leftPair = array[left];
            mymap[leftPair.first]--;
            mymap[leftPair.second]--;

            if (mymap[leftPair.first] == 0) mymap.erase(leftPair.first);
            if (mymap[leftPair.second] == 0) mymap.erase(leftPair.second);
            left++;
        }

        mymap[mypair.first]++;
        mymap[mypair.second]++;

        max_length = max(max_length, (right - left + 1));
    }

    return max_length;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    pair<int, int> mypair = {0,0};
    int x, y, howMany;
    vector<pair<int, int>> array;

    for (int i = 0; i < n; i++)
    {
        int numOfDataSet;
        cin >> numOfDataSet;

        for (int i = 0; i < numOfDataSet; i++)
        {
            cin >> x >> y >> howMany;
            mypair.first = x;
            mypair.second = y;

            for (int i = 0; i < howMany; i++) array.push_back(mypair);
        }

        std::cout << solve(array) << '\n';
    }
    
    return 0;
}