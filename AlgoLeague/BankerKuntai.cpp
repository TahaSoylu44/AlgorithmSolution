#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int MOD;

int fastExp(int A, int B, int K)
{
    if (B == 0 && A == 0) return -1;
    if (A == 0) return 0;
    if (B == 0) return 1;

    if (B % 2) return (fastExp(A, B - 1, K) * A) % K;
    else return (fastExp(A, B/2, K) * fastExp(A, B/2, K)) % K;
}

vector<int> solve(vector<int>& array)
{
    if (array.size() == 1 || array.size() == 0) return array;
    bool isChanged = false;
    vector<int> newArray;

    for (int i = 0; i <= array.size(); i++)
    {
        if (i == array.size()) break;

        if (i == array.size() - 1)
        {
            newArray.push_back(array[i]);
            break;
        }

        if (fastExp(array[i + 1], MOD - 2, MOD) == array[i])
        {
            if (i == array.size() - 2) return solve(newArray);
            isChanged = true;
            i++;
        }

        else newArray.push_back(array[i]);
    }

    if (isChanged) return solve(newArray);
    else return newArray;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size;
    cin >> size >> MOD;
    vector<int> debt(size);

    for (int i = 0; i < size; i++) cin >> debt[i];

    vector<int> result = solve(debt);
    int counter = 0;

    for (int num : result) counter = (counter + num) % MOD;

    std::cout << counter;

    return 0;
}