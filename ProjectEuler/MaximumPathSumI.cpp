#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {

    // SİHİRLİ SATIR BURADA:
    // (Dosyanın tam yolunu yazarsan çalışma dizini hatasından %100 kurtulursun)
    // Örnek Windows yolu: "C:\\Users\\Kullanici\\Desktop\\p067_triangle.txt"
    freopen("/home/tahas44/Desktop/sources/AlgorithmProblems/ProjectEuler/triangle.txt", "r", stdin); 

    vector<vector<int>> triangle(100);

    // Sanki normal terminalden sayı giriyormuşsun gibi cin kullan!
    int number;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> number; // Artık txt dosyasından okuyor!
            triangle[i].push_back(number);
        }
    }

    int num1, num2;

    for (int i = 98; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            num1 = triangle[i + 1][j];
            num2 = triangle[i + 1][j + 1];

            triangle[i][j] += max(num1, num2);
        }
    }

    std::cout << triangle[0][0];
    
    return 0;
}


/*
int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row, int column)
{
    if (row == 15 || triangle[row].size() == column) return 0;
    if (dp[row][column] != -1) return dp[row][column];

    int opt1 = triangle[row][column] + helper(triangle, dp, row + 1, column);
    int opt2 = triangle[row][column] + helper(triangle, dp, row + 1, column + 1);

    return dp[row][column] = max(opt1, opt2);
}

int solve(vector<vector<int>>& triangle)
{
    vector<vector<int>> dp(15, vector<int>(15, -1));
    
    int opt1 = triangle[0][0] + helper(triangle, dp, 1, 0);
    int opt2 = triangle[0][0] + helper(triangle, dp, 1, 1);

    return max(opt1, opt2);
}
*/