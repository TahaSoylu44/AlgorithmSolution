#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int characterReplacement(string s, int k)
{
    vector<int> array(26, 0);
    int left = 0;
    int right = 0;
    int max_freq = 0;
    int max_len = 0;

    for (; right < s.length(); right++)
    {
        array[s[right] - 'A']++;
        max_freq = max(max_freq, array[s[right] - 'A']);

        while ((right - left + 1) - max_freq > k)
        {
            array[s[left] - 'A']--;
            left++;
        }

        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}