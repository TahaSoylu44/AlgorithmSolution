#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long 

void print(vector<string>& array)
{
    if (array.empty()) return;

    for (const string& s : array) std::cout << s << " ";
    std::cout << '\n';
}

vector<string> letterCombinations(string digits)
{
    unordered_map<int, vector<char>> phone;
    phone[2] = {'a', 'b', 'c'};
    phone[3] = {'d', 'e', 'f'};
    phone[4] = {'g', 'h', 'i'};
    phone[5] = {'j', 'k', 'l'};
    phone[6] = {'m', 'n', 'o'};
    phone[7] = {'p', 'q', 'r', 's'};
    phone[8] = {'t', 'u', 'v'};
    phone[9] = {'w', 'x', 'y', 'z'};

    int combinations = 1;
    int index;
    for (const char& c : digits) combinations *= (phone[c - '0'].size());
    int quantity = combinations;
    vector<string> result(combinations);

    for (const char& c : digits)
    {
        quantity /= phone[c - '0'].size();
        index = 0;

        for (int i = 0; i < (combinations / (quantity * phone[c - '0'].size())); i++)
        {
            for (const char& mychar : phone[c - '0'])
            {
                for (int j = 0; j < quantity; j++)
                {
                    result[index].push_back(mychar);
                    index++;
                }
            }
        }
    }

    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> result = letterCombinations("23");
    print(result);
    
    return 0;
}