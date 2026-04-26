#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isPalindrome(string s)
{
    if (s.empty()) return false;
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else return false;
    }
    return true;
}

int solve(string sentence)
{
    string word;
    bool isAdded = false;
    int counter = 0;
    pair<int, int> max_one = {0, 0};

    for (char c : sentence)
    {
        if(isalnum(c))
        {
            char a = tolower(c);
            word.push_back(a);
            if (!isAdded) counter++;
            isAdded = true;
        }

        else
        {
            if(isPalindrome(word))
            {
                if (word.size() > max_one.first) max_one = {word.size(), counter};
            }

            word.clear();
            isAdded = false;
        }
    }

    if (isPalindrome(word))
    {
        if (word.size() > max_one.first) max_one = {word.size(), counter};
    }

    return max_one.second;  // konum
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    std::cout << solve(s);
    
    return 0;
}