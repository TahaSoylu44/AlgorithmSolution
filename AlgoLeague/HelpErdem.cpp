#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<int>& myarray, vector<int>& freq)
{
    int maximum = 0;
    int maxUzunluk;
    int element;
    int subElement;

    for (int i = 1; i < myarray.size(); i++)
    {
        element = myarray[i];
        maxUzunluk = 0;

        for (int j = 0; j < i; j++)
        {
            subElement = myarray[j];

            if (element >= subElement)
            {
                maxUzunluk = max(maxUzunluk, freq[subElement]);
            }
        }

        maximum = max(maximum, maxUzunluk + 1);
        freq[element] = maxUzunluk + 1;
    }
    return maximum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size;
    cin >> size;

    vector<int> myarray(size + 1);
    myarray[0] = 0;

    for (int i = 1; i < size; i++) cin >> myarray[i];

    vector<int> freq(1e6 + 1, 0);

    std::cout << solve(myarray, freq);

    return 0;
}