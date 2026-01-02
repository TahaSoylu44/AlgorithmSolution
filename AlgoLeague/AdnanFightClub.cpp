#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

    int query;
    cin >> query;

    unordered_set<int> myset;
    vector<int> parameters(2);
    int size;

    for (int i = 0; i < query; i++)
    {
        cin >> size;

        for (int i = 0; i < size; i++) cin >> parameters[i];

        if (size == 1)
        {
            myset.insert(parameters[0]);
        }
        else if (size == 2)
        {
            int a = parameters[0];
            int b = parameters[1];

            if (myset.count(a) &&
                myset.count(a - b) && 
                myset.count(a + b))

            {
                std::cout << "GG EZ" << '\n';
            }
            else std::cout << "GLHF" << '\n';
        } 
    }
    
    return 0;
}