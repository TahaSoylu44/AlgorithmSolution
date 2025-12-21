#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isFound(const vector<int> &small, const vector<int> &big, int v)
{
    if (big.size() < small.size()) return isFound(big, small, v);

    unordered_set<int> mySet (small.begin(), small.end());

    for (int i = 0; i < big.size(); i++)
    {
        if (mySet.count(v - big[i])) return true;
    }
    return false;
}

int main() {
    
    vector<int> A = {1, 2, 3};
    vector<int> B = {8, 6, 12};
    int v = 10;

    std::cout << isFound(A, B, v);

    return 0;
}