#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

void solve(string brackets, int& counter, bool& balanced, unordered_map<char, char>& mymap)
{
    stack<char> mystack;

    for (char c : brackets)
    {
        if (!mystack.empty() && mystack.top() == mymap[c]) mystack.pop();
        else mystack.push(c);

        if (mystack.empty()) counter++;
    }
    if (mystack.empty()) balanced = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    string brackets;
    cin >> brackets;

    int counter = 0;
    bool balanced = false;

    unordered_map<char, char> mymap;
    mymap[']'] = '[';
    mymap['}'] = '{';
    mymap[')'] = '(';

    solve(brackets, counter, balanced, mymap);

    if (balanced)
    {
        if (counter >= 2) std::cout << "YES";
        else std::cout << "NO";
    }
    else std::cout << "NO";
    
    return 0;
}