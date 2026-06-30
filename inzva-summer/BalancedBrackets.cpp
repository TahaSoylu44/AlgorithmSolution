#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool solve(string& s)
{
    if (s.empty()) return true;
    map<char,char> brac_map;
    brac_map.insert({'}', '{'});
    brac_map.insert({']', '['});
    brac_map.insert({')', '('});
    stack<char> mystack;

    for (char c : s)
    {
        if (mystack.empty()) mystack.push(c);

        else
        {
            if (brac_map[c] == mystack.top()) mystack.pop();
            else mystack.push(c);
        }
    }

    return mystack.empty();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    if (solve(s)) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}