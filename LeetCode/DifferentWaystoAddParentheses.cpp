#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> get_result_for_substring(unordered_map<string, vector<int>>& dp, string s)
{
    if (!dp[s].empty()) return dp[s];
    bool isMark = false;

    vector<int> right_ones;
    vector<int> left_ones;
    vector<int> result;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            isMark = true;
            right_ones = get_result_for_substring(dp, s.substr(i + 1));
            left_ones = get_result_for_substring(dp, s.substr(0, i));

            for (int l : left_ones)
            {
                for (int r : right_ones) result.push_back(l + r);
            }
        }
        else if (s[i] == '-')
        {
            isMark = true;
            right_ones = get_result_for_substring(dp, s.substr(i + 1));
            left_ones = get_result_for_substring(dp, s.substr(0, i));

            for (int l : left_ones)
            {
                for (int r : right_ones) result.push_back(l - r);
            }
        }
        else if (s[i] == '*')
        {
            isMark = true;
            right_ones = get_result_for_substring(dp, s.substr(i + 1));
            left_ones = get_result_for_substring(dp, s.substr(0, i));

            for (int l : left_ones)
            {
                for (int r : right_ones) result.push_back(l * r);
            }
        }
    }

    if (!isMark) result.push_back(stoi(s));
    return dp[s] = result;
} 

vector<int> diffWaysToCompute(string expression)
{
    unordered_map<string, vector<int>> dp;
    return get_result_for_substring(dp, expression);
}

void print(vector<int>& v)
{
    if (v.empty()) return;
    for (int num : v) std::cout << num << " ";
    std::cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result = diffWaysToCompute("105");
    print(result);
    
    return 0;
}