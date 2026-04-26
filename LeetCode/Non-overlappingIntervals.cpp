#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    vector<vector<int>> order_finish_time;

    for (const vector<int>& v : intervals)
    {
        order_finish_time.push_back({v[1], v[0]});
    }

    sort(order_finish_time.begin(), order_finish_time.end());
    int counter = 1;
    int last_finish_time = order_finish_time[0][0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (order_finish_time[i][1] >= last_finish_time)
        {
            counter++;
            last_finish_time = order_finish_time[i][0];
        }
    }

    return (intervals.size() - counter);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}