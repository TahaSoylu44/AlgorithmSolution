#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<stack<int>> v(6);
    int N, p;
    cin >> N >> p;
    int counter = 0;
    int stack_num, fret;

    for (int i = 0; i < N; i++)
    {
        cin >> stack_num >> fret;
        stack<int>& mystack = v[stack_num - 1];

        if (mystack.empty() || fret > mystack.top())
        {
            mystack.push(fret);
            counter++;
        }
        else if (fret == mystack.top()) continue;
        else if (fret < mystack.top())
        {
            while (!mystack.empty() && fret < mystack.top())
            {
                mystack.pop();
                counter++;
            } 
            if (mystack.empty() || fret > mystack.top())
            {
                mystack.push(fret);
                counter++;
            }
        }
    }

    std::cout << counter;
    
    return 0;
}