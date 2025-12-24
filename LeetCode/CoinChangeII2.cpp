#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins)
{
    vector<int> dp(amount + 1, 0);  // başlangıçta sıfır durum

    // Base Case
    dp[0] = 1;   // 0 TL hiçbir şey almazsam seçilir (1 durum)

    for (int coin : coins)  // coinler sahneye çıkar
    {
        for (int i = coin; i <= amount; i++)    // elde bu parayı tutarım ve kalan miktarı nasıl elde edeceğimi eklerim
        {
            dp[i] += dp[i - coin];  // coini cebe at, kalan miktarı nasıl hesaplayacağın kombinasyondur.
        } 
    }
    return dp[amount];
}

int main() {

    vector<int> v = {1,2,5};
    std::cout << change(5, v);
    
    return 0;
}