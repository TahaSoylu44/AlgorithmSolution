#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& piles, vector<vector<int>>& dpmemory, int left, int right)
{
    if (left < right)
    {
        if (dpmemory[left][right] == -1e9)
        {
            int opt1 = piles[left] - helper(piles, dpmemory, left + 1, right);
            int opt2 = piles[right] - helper(piles, dpmemory, left, right - 1);
            dpmemory[left][right] = (opt1 > opt2) ? opt1 : opt2;
        }
        return dpmemory[left][right];
    }
    return 0;
}

bool stoneGame(vector<int>& piles)
{
    int size = piles.size();
    vector<vector<int>> dpmemory(size, vector<int>(size, -1e9));

    return helper(piles, dpmemory, 0, size - 1) > 0;
}

int main() {
    
    vector<int> piles = {5,17,19,1,15,19,11,9,6,5,11,7,12,12,2,14,3,6,18,3};

    std::cout << stoneGame(piles) << std::endl;
 
    return 0;
}