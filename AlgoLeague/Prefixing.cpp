#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<int,int> mymap;
    int n, z; cin >> n >> z;
    vector<int> array(n);
    for (int i = 0; i < n; i++) cin >> array[i];
    int counter = 0;
    int current = 0;
    mymap[0] = 1;

    for (int num : array)
    {
        current += num;
        if (mymap.count(current - z)) counter += mymap[current - z];
        mymap[current]++;
    }

    std::cout << counter << '\n';
    
    return 0;
}