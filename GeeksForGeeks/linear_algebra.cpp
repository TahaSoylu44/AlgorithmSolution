#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int MOD = 1e9 + 7;

vector<vector<int>> mul_matrix(vector<vector<int>> A, vector<vector<int>> B)
{
    vector<vector<int>> final(A.size(), vector<int>(A.size()));

    final[0][0] = (((A[0][0] * B[0][0]) % MOD) + ((A[0][1] * B[1][0]) % MOD)) % MOD;
    final[0][1] = (((A[0][0] * B[0][1]) % MOD) + ((A[0][1] * B[1][1]) % MOD)) % MOD;
    final[1][0] = (((A[1][0] * B[0][0]) % MOD) + ((A[1][1] * B[1][0]) % MOD)) % MOD;
    final[1][1] = (((A[1][0] * B[0][1]) % MOD) + ((A[1][1] * B[1][1]) % MOD)) % MOD;

    return final;
}

vector<vector<int>> fast_exp(vector<vector<int>>& A, int n)
{
    if (n == 0) return {{1,0}, {0,1}};

    if (n & 1) return mul_matrix(A, fast_exp(A, n - 1));
    else
    {
        vector<vector<int>> half = fast_exp(A, n / 2);
        return mul_matrix(half, half);
    }
}


int fibonacci(int n)
{
    if (n == 0 || n == 1) return 1;
    vector<vector<int>> base = {{1,1}, {1,0}};
    vector<vector<int>> matrix_exp = fast_exp(base, n - 1);
    return (matrix_exp[0][0] + matrix_exp[0][1]) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    std::cout << fibonacci(n) << '\n';
    
    return 0;
}