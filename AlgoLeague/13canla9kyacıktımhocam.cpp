#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int MOD = 1e9 + 7;

int how_many(vector<int>& cards, int target)
{
    map<int,vector<int>> mymap;
    int counter = 0;

    for (int i = 0; i < cards.size(); i++)
    {
        if (mymap.contains(target - cards[i])) counter = (counter + 1) % MOD;

        for(auto const& [key, val] : mymap)
        {
            int newValue = key + cards[i];
            vector<int> arr = val;
            arr.push_back(i);
            mymap.insert({newValue, arr});
        }

        mymap.insert({cards[i],{i}});
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int berke_left = 3668;
    int berke_right = 3668;
    int anil_left = 4424;
    int anil_right = 4424;
    int berke_left_leave = 13;
    int berke_right_leave = 962;
    int anil_left_leave = 0;
    int anil_right_leave = 86;

    vector<int> cards(8);
    for (int i = 0; i < 8; i++) cin >> cards[i];
    
    return 0;
}