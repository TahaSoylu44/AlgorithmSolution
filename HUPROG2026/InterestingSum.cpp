#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int fastExp(int a, int b)
{
    if (a == 0 && b == 0) return -1;
    if (a == 0) return 0;
    if (b == 0) return 1;

    if (b % 2) return a * fastExp(a, b - 1);
    else
    {
        int half = fastExp(a, b / 2);
        return half * half;
    }
}

int solve(string s)
{
    int size = s.size();
    vector<char> char_array(size);
    
    for (int i = 0; i < size; i++) char_array[i] = s[i];
    sort(char_array.begin(), char_array.end());

    int total = 0;
    int number;

    for (int i = 0; i < size; i++)
    {
        number = char_array[i] - '0';
        total += number * fastExp(10, i);
        total += number * fastExp(10, size - 1 - i);
    }

    return total;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    std::cout << solve(s);
    
    return 0;
}