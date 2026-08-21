#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

string longestPalindrome(string s)
{
    int length = s.length();
    vector<vector<bool>> dp(length, vector<bool>(length, false));
    for (int i = 0; i < length; i++) dp[i][i] = true;

    int max_i = 0;
    int max_j = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < length; j++)
        {
            if ((s[i] == s[j]))
            {
                if ((dp[i + 1][j - 1]) || (j == i + 1))
                {
                    dp[i][j] = true;

                    if ((j - i) > (max_j - max_i))
                    {
                        max_j = j;
                        max_i = i;
                    }
                }
            }
        }
    }

    string result = "";
    for (int i = max_i; i <= max_j; i++) result.push_back(s[i]);
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}