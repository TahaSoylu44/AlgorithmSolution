#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool solve(vector<int>& moves, vector<int>& dp, int remaining)
{
    if (dp[remaining] != -1) return dp[remaining];
    int option = 0;

    for (int move : moves)
    {
        if (move <= remaining)
        {
            if (solve(moves, dp, remaining - move) == 0)
            {
                option = 1;
                break;
            }
        }
    }

    return dp[remaining] = option;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> moves(k);
    for (int i = 0; i < k; i++) cin >> moves[i];

    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    stack<char> mystack;

    for (int i = n; i >= 1; i--)
    {
        if (solve(moves, dp, i)) mystack.push('W');
        else mystack.push('L');
    }

    while (!mystack.empty())
    {
        std::cout << mystack.top();
        mystack.pop();
    }
    
    return 0;
}