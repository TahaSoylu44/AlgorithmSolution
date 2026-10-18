#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> array;
    array.push_back(intervals[0]);

    vector<int> v;
    vector<int> back_one;

    for (int i = 1; i < intervals.size(); i++)
    {
        v = intervals[i];

        if ((v[0] >= array.back()[0]) && (v[0] <= array.back()[1]))
        {
            back_one = array.back();
            array.pop_back();
            array.push_back({back_one[0], max(v[1], back_one[1])});
        }
        else array.push_back(v);
    }
    return array;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}