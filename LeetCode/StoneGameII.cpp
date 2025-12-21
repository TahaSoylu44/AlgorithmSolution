#include <iostream>
#include <vector>

using namespace std;

int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

vector<int> presumVector(vector<int>& piles)
{
    int size = piles.size();

    vector<int> myvector(size);
    myvector[size - 1] = piles[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        myvector[i] = piles[i] + myvector[i + 1];
    } 
    return myvector;
}

int helper(vector<int>& presum, vector<vector<int>>& dp,int index, int M)
{
    if (index >= presum.size()) return 0;   // siniri geciyorsa bye bye,yok bisey

    if (index + 2*M >= presum.size()) return presum[index]; // hepsini alabiliyorsan, al kac

    if (dp[index][M] != -1) return dp[index][M];

    int maxSum = 0;

    for (int i = 1; i < 2* M + 1; i++)  // tas sayısı
    {
        int opponent = helper(presum, dp, index + i, getMax(M, i)); // rakip en iyi ne yapar?
        int me = presum[index] - opponent;  // bana kalan

        maxSum = getMax(maxSum, me);
    } 
    return dp[index][M] = maxSum;
}

int stoneGameII(vector<int>& piles)
{
    vector<int> presum = presumVector(piles);

    int size = piles.size();

    vector<vector<int>> dp(size, vector<int>(size + 1, -1));

    return helper(presum, dp, 0, 1);
}

int main() {

    vector<int> piles = {2,7,9,4,4};
    std::cout << stoneGameII(piles);
    
    return 0;
}