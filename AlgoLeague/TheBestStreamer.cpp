#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> table;
    set<pair<int,string>> myset;

    int num_of_query, query, view;
    string name;
    cin >> num_of_query;

    for (int i = 0; i < num_of_query; i++)
    {
        cin >> query;

        if (query == 1)
        {
            cin >> name >> view;

            if (table.count(name)) if (myset.count({-table[name], name})) myset.erase({-table[name], name});
            table[name] = view;
            myset.insert({-view, name});
        }
        else if (query == 2)
        {
            cin >> name;

            if (table.count(name))
            {
                if (myset.count({-table[name], name})) myset.erase({-table[name], name});
                table.erase(name);
            }
        }
        else if (query == 3)
        {
            if (myset.empty()) std::cout << "None" << '\n';
            else std::cout << myset.begin()->second << '\n';
        }
        else if (query == 4)
        {   
            if (myset.size() < 2) std::cout << 0 << '\n';
            else
            {
                int maximum = myset.begin()->first * -1;
                int minimum = myset.rbegin()->first * -1;
                std::cout << maximum - minimum << '\n';
            }
        }
    }
    
    return 0;
}