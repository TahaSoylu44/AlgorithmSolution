#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void backtrack(int start, vector<int>& comb, vector<vector<int>>& result, int n, int k)
{
    if (comb.size() == k) 
    {
        result.push_back(comb);
        return;
    }

    for (int i = start; i <= n; i++)
    {
        comb.push_back(i);
        backtrack(i + 1, comb, result, n, k);
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> comb = {};
    backtrack(1, comb, result, n, k);
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}