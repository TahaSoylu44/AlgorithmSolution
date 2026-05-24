#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<string> myset;
    myset.insert("Ahmed");
    myset.insert("Faruk");
    myset.insert("Ozgur");
    myset.insert("Anil");
    myset.insert("Dervisoglu");
    myset.insert("Altay");
    myset.insert("Kilic");
    myset.insert("Berk");
    myset.insert("Sel");
    myset.insert("Berke");
    myset.insert("Donmez");
    myset.insert("Enes");
    myset.insert("Cakil");
    myset.insert("Enes");
    myset.insert("Sacak");
    myset.insert("Mustafa");
    myset.insert("Yunus");
    myset.insert("Diler");
    myset.insert("Ekin");
    myset.insert("Sert");
    myset.insert("Emre");
    myset.insert("Tahtali");
    myset.insert("Muhittin");
    myset.insert("Koybasi");
    myset.insert("Mustafa");
    myset.insert("Bozdogan");
    myset.insert("Tahsin");
    myset.insert("Tanrikulu");

    string s;
    cin >> s;

    if (myset.count(s))
    {
        std::cout << "YES" << '\n';
    }
    else std::cout << "NO" << '\n';
    
    return 0;
}