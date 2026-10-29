#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

string recursive(string& s, int& index)
{
    int repeat;
    string repeat_string;
    string mystring;
    string substring;

    for (; index < s.length(); index++)
    {
        if (isdigit(s[index])) repeat_string.push_back(s[index]);
        else if (s[index] == '[')
        {
            index++;
            repeat = stoi(repeat_string);
            substring = recursive(s, index);
            for (int i = 0; i < repeat; i++) mystring += substring;
            repeat_string.clear();
        }
        else if (s[index] == ']') return mystring;
        else mystring.push_back(s[index]);
    }

    return mystring;
}

string decodeString2(string s)
{
    int index = 0;
    return recursive(s, index);
}

string decodeString(string s)
{
    stack<char> mystack;
    stack<char> for_reverse;
    int repeat;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ']')
        {
            vector<int> array;
            string repeat_string;

            while (!mystack.empty())
            {
                if (mystack.top() == '[')
                {
                    mystack.pop();
                    break;
                }
                array.push_back(mystack.top());
                mystack.pop();
            }

            while ((!mystack.empty()) && (isdigit(mystack.top())))
            {
                for_reverse.push(mystack.top());
                mystack.pop();
            }

            while (!for_reverse.empty())
            {
                repeat_string.push_back(for_reverse.top());
                for_reverse.pop();
            }

            repeat = stoi(repeat_string);

            for (int j = 0; j < repeat; j++)
            {
                for (int k = array.size() - 1; k >= 0; k--) mystack.push(array[k]);
            }
        }
        else mystack.push(s[i]);
    }

    while (!mystack.empty())
    {
        for_reverse.push(mystack.top());
        mystack.pop();
    }

    string result;

    while (!for_reverse.empty())
    {
        result.push_back(for_reverse.top());
        for_reverse.pop();
    }

    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    std::cout << decodeString2(s) << '\n';
    
    return 0;
}