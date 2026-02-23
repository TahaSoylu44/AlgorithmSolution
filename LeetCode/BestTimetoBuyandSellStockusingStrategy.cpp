#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

vector<int> preSum(vector<int>& prices, vector<int>& strategy)  // strategy kullanılarak oluşturulmuş prefix sum array
{
    vector<int> presum(prices.size() + 1);
    presum[0] = 0;

    for (int i = 1; i <= prices.size(); i++) presum[i] = presum[i - 1] + prices[i - 1] * strategy[i - 1];
    return presum;
}

vector<int> prefixSumForPrices(vector<int>& prices) // sadece prices muhatap alındığı prefix sum array
{
    vector<int> summing(prices.size() + 1);
    summing[0] = 0;
    for (int i = 1; i <= prices.size(); i++) summing[i] = summing[i - 1] + prices[i - 1];
    return summing;
}

long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
{
    vector<int> presumProfits = preSum(prices, strategy);
    vector<int> prefixSum = prefixSumForPrices(prices);
    int sumProfit = presumProfits.back();   // toplam genel profit
    int currentSum; // işlemler sırasında oluşan profit
    int startIdx;   // k / 2 kullanacaz, yeni bir index değeri oluşacak
    int maxSum = sumProfit; // max profit

    for (int i = 0; i <= prices.size() - k; i++)
    {
        currentSum = sumProfit - (presumProfits[k + i] - presumProfits[i]); // sliding window anlık gösterdiği değer gemel profitten çıkarılır
        startIdx = i + (k / 2); // last k / 2 "1" değerinde
        currentSum += (prefixSum[startIdx + (k / 2)] - prefixSum[startIdx]);    // yeni değerleri ekle
        maxSum = max(maxSum, currentSum);   // maximum al
    }

    return maxSum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> prices = {4, 2, 8};
    vector<int> strategy = {-1, 0, 1};
    std::cout << maxProfit(prices, strategy, 2);
    
    return 0;
}