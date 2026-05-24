#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<pair<int, string>> myset;
    unordered_set<string> names;

    int num_of_queries;
    cin >> num_of_queries;
    map<string, int> mymap;
    int type;
    string name;
    int view_count;

    for (int i = 0; i < num_of_queries; i++)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> name;
            if (names.count(name)) myset.erase({mymap[name], name});
            names.insert(name);

            cin >> view_count;
            mymap[name] = view_count;
            myset.insert({view_count, name});
        }
        else if (type == 2)
        {
            cin >> name;

            if (names.count(name))
            {
                myset.erase({mymap[name], name});
                mymap.erase(name);
            }
        }
        else if (type == 3)
        {
            pair<int,string> mypair = *(myset.end());
            if (mymap.size() > 0) std::cout << mypair.second << '\n';
            else std::cout << "None" << '\n';
        }
        else if (type == 4)
        {
            pair<int,string> minpair = *(myset.begin());
            pair<int,string> maxpair = *(myset.end());
            if (mymap.size() < 2) std::cout << 0 << '\n';
            else std::cout << (maxpair.first - minpair.first) << '\n';
        }
    }
    
    return 0;
}