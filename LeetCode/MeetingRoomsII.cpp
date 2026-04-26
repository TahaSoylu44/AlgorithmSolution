#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:    
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int counter = 1;
        priority_queue<int> pq;
        pq.push(intervals[0][1] * -1);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= (pq.top() * -1)) pq.pop();
            else counter++;
            pq.push(intervals[i][1] * -1);
        }
        return counter;
    }
};

int main()
{
    vector<vector<int>> input = {{0, 30}, {5, 10}, {15, 20}};
    Solution s;
    cout << s.minMeetingRooms(input) << '\n';

    return 0;
}