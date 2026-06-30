#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> suffix_array;
    string mystring = "";

    for (int i = n - 1; i >= 0; i--)
    {
        mystring = s[i] + mystring;
        suffix_array.push_back(mystring);
    }

    sort(suffix_array.begin(), suffix_array.end());

    int max_pharse = 0;

    string s1;
    string s2;
    int j;

    for (int i = 1; i < suffix_array.size(); i++)
    {
        s1 = suffix_array[i - 1];
        s2 = suffix_array[i];
        j = max_pharse;

        while ((j < s1.size()) && (j < s2.size()))
        {
            if (s1[j] != s2[j])
            {
                max_pharse = max(max_pharse, j);
                break;
            }
            j++;
            if (j >= s1.size() || j >= s2.size()) max_pharse = max(max_pharse, j);
        }
    }

    std::cout << max_pharse;
    
    return 0;
}