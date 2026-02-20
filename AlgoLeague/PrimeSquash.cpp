#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void sieve(vector<bool>& primeArray, int maximum)
{
    primeArray[1] = false;
    
    for (int i = 2; i <= maximum; i++)
    {
        if (!primeArray[i]) continue;

        for (int j = i * i; j <= maximum; j += i) primeArray[j] = false;
    }   
}

int solve(vector<int>& numbers, vector<bool>& primeArray, int most, int maximum)
{
    int counter = 0;
    int left = 0;
    int distinct = 0;
    vector<int> freq(maximum + 1, 0);

    for (int i = 0; i < numbers.size(); i++)
    {
        int current_item = numbers[i];
        if (primeArray[current_item])
        {
            if (freq[current_item] == 0) distinct++;
            freq[current_item]++;
        }

        while (distinct > most)
        {
            int left_item = numbers[left];
            if (primeArray[left_item])
            {
                if (freq[left_item] == 1) distinct--;
                freq[left_item]--;
            }
            left++;
        }

        counter += i - left + 1;
    }
    return counter;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size, most;
    cin >> size >> most;

    int maximum = 0;

    vector<int> numbers(size);

    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;

        maximum = max(maximum, x);
        numbers[i] = x;
    }

    vector<bool> primeArray(maximum + 1, true);
    sieve(primeArray, maximum);

    int ans = solve(numbers, primeArray, most, maximum);

    std::cout << ans;
    
    return 0;
}