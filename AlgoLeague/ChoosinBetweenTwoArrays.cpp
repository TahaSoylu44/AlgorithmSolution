#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long helper(vector<long long>& A, vector<long long>& B, long long idx, long long penalty, long long type, vector<vector<long long>>& dp)
{
    if (idx >= A.size()) return 0;  // Base case

    if (dp[idx][type] != -1) return dp[idx][type];

    if (idx == 0)
    {
        long long opt1 = A[idx] + helper(A, B, idx + 1, penalty, 0, dp);
        long long opt2 = B[idx] + helper(A, B, idx + 1, penalty, 1, dp);

        if (opt1 < opt2) return dp[idx][0] = opt1; 
        else return dp[idx][1] = opt2;
    }
    else
    {
        long long opt1, opt2;

        if (type == 0)  // A dan alınmış daha önce  
        {
            opt1 = A[idx] + helper(A, B, idx + 1, penalty, 0, dp);
            opt2 = penalty + B[idx] + helper(A, B, idx + 1, penalty, 1, dp);
        }
        else    // B den alınmış daha önce
        {
            opt1 = penalty + A[idx] + helper(A, B, idx + 1, penalty, 0, dp);
            opt2 = B[idx] + helper(A, B, idx + 1, penalty, 1, dp);
        }

        if (opt1 < opt2) return dp[idx][0] = opt1; 
        else return dp[idx][1] = opt2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long size, penalty;

    cin >> size >> penalty;

    vector<long long> A(size);
    vector<long long> B(size);

    for (long long i = 0; i < size; i++) cin >> A[i];
    for (long long i = 0; i < size; i++) cin >> B[i];

    vector<vector<long long>> dp(size, vector<long long>(2, -1));

    std::cout << helper(A, B, 0, penalty, 1, dp);
    
    return 0;
}