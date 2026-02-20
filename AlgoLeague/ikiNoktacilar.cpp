#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int howManySmall(vector<int>& frequency, int number)
{
    int counter = 0;
    for (int i = 0; i < number; i++) counter += frequency[i];
    return counter;
}

int howManyBig(vector<int>& frequency, int number)
{
    int counter = 0;
    for (int i = number + 1; i < 51; i++) counter += frequency[i];
    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> frequency(51, 0);

    int n, k;
    cin >> n >> k;

    vector<int> array(n);

    for (int i = 0; i < n; i++) cin >> array[i];

    int left = 0;
    int counter = 0;
    int now;

    for (int right = 0; right < n; right++)
    {
        now = array[right];
        frequency[now]++;
        k -= howManyBig(frequency, now);

        while (k < 0)
        {
            int leftNumber = array[left];
            
            k += howManySmall(frequency, leftNumber);
            frequency[leftNumber]--;
            left++;
        }

        counter += (right - left + 1);
    }

    std::cout << counter;
    
    return 0;
}