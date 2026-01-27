#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void solve(set<int>& myset, int a)  // THE TRIAL DIVISON
{
    if (a % 2 == 0) // önce 2 sayısına bakalim
    {
        myset.insert(2);
        while (a % 2 == 0) a /= 2;  // tüm 2 leri tüket.
    }

    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
        {
            myset.insert(i);
            while (a % i == 0) a /= i;  // sonradan buna bölünebilen bir sayi kalmasin diye tüket
        }
    }

    if (a > 1) myset.insert(a); // eğer 1 den büyükse bir asal carpan kalmistir.
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<int> myset;

    int times;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
        {
            solve(myset, a);
            if (a % b != 0) solve(myset, b);
        }
        else
        {
            solve(myset, b);
            if (b % a != 0) solve(myset, a);
        }
        
        std::cout << myset.size() << '\n';

        myset.clear();
    }
    
    return 0;
}