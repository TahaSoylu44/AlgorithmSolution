#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void compress(string& s)
{
    if (s.size() <= 1) return;

    vector<pair<char,int>> groups;
    
    char c = s[0];
    int counter = 1;
    bool isChanged = false; 

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            counter++;
            isChanged = true; 
        }
        else
        {
            groups.push_back({c, counter}); 
            c = s[i];      
            counter = 1;   
        }
    }
    groups.push_back({c, counter});

    if (!isChanged) return;

    string newS = "";
    for (const auto& p : groups)
    {
        newS += p.first;
        if (p.second > 1) 
        {
            newS += to_string(p.second);
        }
    }

    if (newS == s) return;

    s = newS;
    compress(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    if (cin >> size) { 
        string s;
        cin >> s;

        compress(s);
        std::cout << s;
    }

    return 0;
}