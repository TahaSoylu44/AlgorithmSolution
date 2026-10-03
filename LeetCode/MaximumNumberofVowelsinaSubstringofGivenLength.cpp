#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int maxVowels(string s, int k)
{
    int result;
    int counter = 0;
    unordered_set<char> myset = {'a', 'e', 'u', 'i', 'o'};

    for (int i = 0; i < k; i++) 
    {
        if (myset.count(s[i])) counter++;
    }

    result = counter;

    for (int i = 1; i <= s.length() - k; i++)
    {
        if (myset.count(s[i - 1])) counter--;
        if (myset.count(s[i + k - 1])) counter++;
        result = max(result, counter);
    }

    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    std::cout << maxVowels("abciiidef", 3) << '\n';
    
    return 0;
}