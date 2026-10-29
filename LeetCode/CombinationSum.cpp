#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void print(vector<vector<int>>& matrix)
{
    if (matrix.empty()) return;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int num : matrix[i]) std::cout << num << " ";
        std::cout << '\n';
    }
}

void recursive(vector<vector<int>>& overall, vector<int>& process, int i, vector<int>& candidates, int target, int sum)
{
    if (sum > target) return;

    if (sum == target)
    {
        overall.push_back(process);
        return;
    }

    for (int index = i; index < candidates.size(); index++)
    {
        process.push_back(candidates[index]);
        recursive(overall, process, index, candidates, target, sum + candidates[index]);
        process.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> overall;
    vector<int> process;

    for (int i = 0; i < candidates.size(); i++)
    {
        process.push_back(candidates[i]);
        recursive(overall, process, i, candidates, target, candidates[i]);
        process.pop_back();
    }

    return overall;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> result = combinationSum(candidates, target);
    print(result); 
    
    return 0;
}