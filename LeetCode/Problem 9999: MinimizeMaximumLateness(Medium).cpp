#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeMaximumLateness(vector<vector<int>>& projects) 
    {
        sort(projects.begin(), projects.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });

        int now = 0;
        int lateness = 0;

        for (const vector<int>& project : projects)
        {
            now += project[0];
            lateness = max(lateness, (now - project[1]));
        }
        return lateness;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> projects = {{2, 15}, {3, 6}, {4, 9}, {1, 9}, {2, 8}, {3, 14}};
    Solution s;
    std::cout << s.minimizeMaximumLateness(projects) << '\n';

    return 0;
}