#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++) cin >> array[i];

    vector<int> left_to_right(n,0);
    vector<int> right_to_left(n,0);
    stack<pair<int,int>> mystack;
    pair<int,int> mypair;

    for (int i = 0; i < n; i++)
    {
        while (!mystack.empty() && (array[i] >= mystack.top().first))
        {
            mypair = mystack.top();
            mystack.pop();
            left_to_right[mypair.second] = i - mypair.second;
        }
        mystack.push({array[i],i});
    }

    stack<pair<int,int>> mystack;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!mystack.empty() && (array[i] >= mystack.top().first))
        {
            mypair = mystack.top();
            mystack.pop();
            right_to_left[mypair.second] = mypair.second - i;
        }
        mystack.push({array[i],i});
    }

    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (left_to_right[i] == 0) counter += (n - i);
        else counter += left_to_right[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (right_to_left[i] == 0) counter += (n - i);
        else counter += right_to_left[i];
    }

    return 0;
}