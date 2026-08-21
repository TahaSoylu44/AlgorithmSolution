#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool permutation(int left, int right, string& s2, map<char,int> char_map, set<char> char_set)
{
    map<char,int> inner_map;

    for (int i = left; i <= right; i++)
    {
        if (char_set.count(s2[i])) inner_map[s2[i]]++;
    }

    if (inner_map.size() != char_map.size()) return false;

    for (char c : char_set)
    {
        if (inner_map[c] != char_map[c]) return false;
    }

    return true;
}

bool checkInclusion(string s1, string s2) 
{
    if (s1.length() > s2.length()) return false;
    int w_size = s1.length();
    map<char,int> char_map;
    set<char> char_set;
    for (char c : s1)
    {
        char_map[c]++;
        char_set.insert(c);
    }

    for (int i = 0; i <= s2.length() - w_size; i++)
    {
        if (permutation(i, i + w_size - 1, s2, char_map, char_set)) return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}