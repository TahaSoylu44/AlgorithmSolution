#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int get_max(vector<vector<int>>& matrix, vector<int>& dp, int state)
{
    int N = matrix.size();
    int i = __builtin_popcount(state);
    
    // Base Case (Taban Durumu): Tüm satırlar bittiyse eklenecek puan kalmamıştır
    if (i == N) return 0;
    
    // DP Kalkanı: Daha önce bu duruma geldiysek sonucu direkt tablodan ver
    if (dp[state] != -1) return dp[state];
    
    int new_mask;
    int ans = -1e18; // Maksimum aradığımız için sonsuz küçük

    for (int j = 0; j < N; j++)
    {
        // Eğer bu sütun daha önce alındıysa atla
        if ((state >> j) & 1) continue;
        
        new_mask = state | (1 << j);
        ans = max(ans, matrix[i][j] + get_max(matrix, dp, new_mask));
    }

    // KRİTİK NOKTA: Bulunan cevabı mutlaka DP tablosuna KULLANARAK döndür!
    return dp[state] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cin >> matrix[i][j];
    }

    // Tabloyu tamamen -1 ile dolduruyoruz
    vector<int> dp((1 << N), -1);
    
    // dp[0] = 0; SİLİNDİ! Başlangıç state'ini (0) doğrudan yolluyoruz
    std::cout << get_max(matrix, dp, 0);

    return 0;
}