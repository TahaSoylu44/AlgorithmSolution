#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {return a * b / gcd(a, b);}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}