#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void print(vector<vector<string>>& array)
{
    if (array.empty()) return;

    for (int i = 0; i < array.size(); i++)
    {
        for (string& s : array[i]) std::cout << s << " ";
        std::cout << '\n';
    }
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> mymap;
    string mystring;

    for (int i = 0; i < strs.size(); i++)
    {
        mystring = strs[i];
        sort(mystring.begin(), mystring.end());
        mymap[mystring].push_back(strs[i]);
    } 

    vector<vector<string>> array;
    for (auto& [key,value] : mymap) array.push_back(value);
    return array;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> array = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(array);
    print(result);
    
    return 0;
}