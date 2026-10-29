#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

string reverseParenthese2(string s)
{
    stack<int> index_of_open_paran;
    unordered_map<int,int> mymap;
    int index;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') index_of_open_paran.push(i);

        else if (s[i] == ')')
        {
            index = index_of_open_paran.top();
            index_of_open_paran.pop();

            mymap[index] = i;
            mymap[i] = index;
        }
    }

    int direction = 1;
    index = 0;
    string result;

    while (index < s.length())
    {
        if ((s[index] == '(') || (s[index] == ')'))
        {
            direction *= -1;
            index = mymap[index];
            index += direction;
            continue;
        }

        result.push_back(s[index]);
        index += direction;
    }

    return result;
}

string reverseParentheses(string s)
{
    stack<char> mystack;
    queue<char> myqueue;
    char c;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            while (!mystack.empty())
            {
                c = mystack.top();
                mystack.pop();
                if (c == '(') break;

                myqueue.push(c);
            }

            while (!myqueue.empty())
            {
                c = myqueue.front();
                myqueue.pop();
                mystack.push(c);
            }
        }
        else mystack.push(s[i]);
    }

    stack<char> another_stack;

    while (!mystack.empty())
    {
        another_stack.push(mystack.top());
        mystack.pop();
    }

    string result;

    while (!another_stack.empty())
    {
        result.push_back(another_stack.top());
        another_stack.pop();
    }    
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    std::cout << reverseParenthese2(s) << '\n';
    
    return 0;
}