#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int fastExp(int A, int B, int K)
{
    if (B == 0 && A == 0) return -1;
    if (A == 0) return 0;
    if (B == 0) return 1;

    if (B % 2) return (fastExp(A, B - 1, K) * A) % K;
    else return (fastExp(A, B/2, K) * fastExp(A, B/2, K)) % K;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, K;
    cin >> A >> B >> K;

    std::cout << fastExp(A, B, K);

    return 0;
}