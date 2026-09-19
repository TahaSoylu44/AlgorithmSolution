#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int left = 0;
    int right = N;
    int number;
    int left_length;
    int right_length;

    std::cout << "? " << 0 << endl;
    cin >> left_length;
    if (left_length == 0) return 0;

    std::cout << "? " << N << endl;
    cin >> right_length;
    if (right_length == 0) return 0;

    int cell = N / 2;
    std::cout << "? " << cell << endl;
    cin >> number;

    while (number != 0)
    {
        if (number == -1) break;

        if (number == left_length) left = cell;
        else right = cell;

        cell = (right + left) / 2;
        std::cout << "? " << cell << endl;
        cin >> number;
    }
    
    return 0;
}