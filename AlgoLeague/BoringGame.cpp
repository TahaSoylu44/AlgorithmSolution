#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b % a, a);
}

int solveGCD(vector<int>& gcdDP, vector<int>& array, int quantity)
{
    if (quantity == 1) return array[0];
    if (gcdDP[quantity] != -1) return gcdDP[quantity];
    return gcdDP[quantity] = gcd(solveGCD(gcdDP, array, quantity - 1), array[quantity - 1]);
}

bool helper(vector<int>& array, int x, int me, int enemy, vector<vector<vector<int>>>& dp, vector<int>& gcdDp)
{
    if (dp[x][me][enemy] != -1) return dp[x][me][enemy];
    int gcd_value = solveGCD(gcdDp, array, x);

    if (gcd_value < x) return dp[x][me][enemy] = 0;
    else
    {
        if (me)
        {
            bool opt1 = helper(array, x, enemy, 0, dp, gcdDp);  // passing
            bool opt2 = helper(array, x + 1, enemy, me, dp, gcdDp); // increase

            if (!(opt1 * opt2)) return dp[x][me][enemy] = 1;
            else return dp[x][me][enemy] = 0;
        }
        else return dp[x][me][enemy] = helper(array, x + 1, enemy, me, dp, gcdDp); // increase
    }
}

void solve(vector<int>& array, int x, vector<int>& gcdDp, vector<vector<vector<int>>>& dp)
{
    bool result = helper(array, x, 1, 1, dp, gcdDp);

    if (result) std::cout << "Melih" << '\n';
    else std::cout << "Tahsin" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numOfElements, numOfTestCases;
    cin >> numOfElements >> numOfTestCases;

    vector<int> gcdDP(numOfElements + 1, -1);
    vector<int> array(numOfElements);  
    
    for (int i = 0; i < numOfElements; i++) cin >> array[i];
    vector<vector<vector<int>>> dp(array.size() + 1, vector<vector<int>>(2, vector<int>(2, -1)));

    for (int i = 0; i < numOfTestCases; i++)
    {
        int x;
        cin >> x;
        solve(array, x, gcdDP, dp);
    }

    return 0;
}