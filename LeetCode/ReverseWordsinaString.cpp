#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

string reverseWords(string s)
{
    string mystring;
    vector<string> array;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (!mystring.empty())
            {
                array.push_back(mystring);
                mystring.clear();
            }
        }
        else mystring.push_back(s[i]);
    }
    if (!mystring.empty()) array.push_back(mystring);
    mystring.clear();

    for (int i = array.size() - 1; i >= 0; i--)
    {
        mystring.append(array[i]);
        if (i == 0) break;
        mystring.push_back(' ');
    }

    return mystring;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << reverseWords("   taha is   sch") << '\n';
    
    return 0;
}