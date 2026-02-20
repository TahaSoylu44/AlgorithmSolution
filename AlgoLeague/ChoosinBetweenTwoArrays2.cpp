#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int helper(vector<int>& arrayA, vector<int>& arrayB, int index, int penalty, int lastOne, vector<vector<int>>& dp)
{
    if (index == 0) // ilk defa geldi
    {
        int opt1 = arrayA[index] + helper(arrayA, arrayB, index + 1, penalty, 0, dp);  // a dan aldım
        int opt2 = arrayB[index] + helper(arrayA, arrayB, index + 1, penalty, 1, dp);  // b dan aldım

        dp[0][0] = min(opt1, opt2);
        dp[0][1] = min(opt1, opt2);

        return min(opt1, opt2);
    }

    if (index == arrayA.size()) return 0;
    if (dp[index][lastOne] != -1) return dp[index][lastOne];

    int opt1, opt2;

    if (lastOne == 0) // daha önce a dan almıştım
    {
        opt1 = arrayA[index] + helper(arrayA, arrayB, index + 1, penalty, 0, dp);  // a dan aldım
        opt2 = penalty + arrayB[index] + helper(arrayA, arrayB, index + 1, penalty, 1, dp);  // b dan aldım
    }
    else if (lastOne == 1)    // daha önce b den almıştım
    {
        opt1 = penalty + arrayA[index] + helper(arrayA, arrayB, index + 1, penalty, 0, dp);  // a dan aldım
        opt2 = arrayB[index] + helper(arrayA, arrayB, index + 1, penalty, 1, dp);  // b dan aldım
    }

    return dp[index][lastOne] = min(opt1, opt2);
}

int minScore(vector<int>& arrayA, vector<int>& arrayB, int penalty)
{
    vector<vector<int>> dp(arrayA.size(), vector<int>(2, -1));
    return helper(arrayA, arrayB, 0, penalty, 1, dp);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, penalty;
    cin >> size >> penalty;

    vector<int> arrayA(size);
    vector<int> arrayB(size);

    for (int i = 0; i < size; i++) cin >> arrayA[i];
    for (int i = 0; i < size; i++) cin >> arrayB[i];

    std::cout << minScore(arrayA, arrayB, penalty);
    
    return 0;
}