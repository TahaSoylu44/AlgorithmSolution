#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> result(temperatures.size());
    stack<pair<int,int>> mystack;
    pair<int,int> mypair;

    for (int i = 0; i < temperatures.size(); i++)
    {
        if (mystack.empty()) mystack.push({temperatures[i], i});

        else
        {
            while (!mystack.empty() && temperatures[i] > mystack.top().first)
            {
                mypair = mystack.top();
                mystack.pop();
                result[mypair.second] = i - mypair.second;
            }
            mystack.push({temperatures[i], i});
        }
    }
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}