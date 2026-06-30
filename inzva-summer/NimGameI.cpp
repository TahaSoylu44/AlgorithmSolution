#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isZero(vector<int>& array)
{
    int result = array[0];
    for (int i = 1; i < array.size(); i++) result = result ^ array[i];
    return result == 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> array;
    int iter, n, num;
    cin >> iter;

    for (int i = 0; i < iter; i++)
    {
        array.clear();
        cin >> n;
        
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            array.push_back(num);
        }

        if (isZero(array)) std::cout << "second" << '\n';
        else std::cout << "first" << '\n';
    }
    
    return 0;
}