#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool solve(vector<int>& nums, int m)
{
    int size = nums.size();
    queue<pair<int,int>> q;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] == m || nums[j] == m) return true;
            int number = nums[i] ^ nums[j];
            if (number == m) return true;
            q.push({number, j});
        }
    }

    while (!q.empty())
    {
        pair<int,int> mypair = q.front();
        q.pop();
        int chosen = mypair.first;
        int last_column = mypair.second;
        if (chosen == m) return true;

        for (int i = last_column + 1; i < size; i++)
        {
            int newNumber = chosen ^ nums[i];
            if (newNumber == m) return true;
            q.push({newNumber, i});
        }
    }

    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    if (solve(nums, m)) std::cout << "yes" << '\n';
    else std::cout << "no" << '\n';
    
    return 0;
}