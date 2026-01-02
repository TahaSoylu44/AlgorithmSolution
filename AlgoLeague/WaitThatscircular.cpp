#include <iostream>
#include <vector>

using namespace std;

long long request(long long num, long long microservice_id, vector<long long>& next_microservice, vector<long long>& secret_number)
{
    if (num <= 0) return num;
    else return request(num - secret_number[microservice_id], next_microservice[microservice_id], next_microservice, secret_number);
}

int helper(long long num, long long microservice_id, vector<long long>& next_microservice, vector<long long>& secret_number, vector<vector<long long>>& dp)
{
    if (num <= 0) return num;

    if (num >= dp.size() || microservice_id >= dp[0].size()) return request(num, microservice_id, next_microservice, secret_number);
    else
    {
        if (dp[num][microservice_id] != -1) return dp[num][microservice_id];

        else return dp[num][microservice_id] = helper(num - secret_number[microservice_id], next_microservice[microservice_id], next_microservice, secret_number, dp);
    }
}

int getResult(long long num, long long microservice_id, vector<long long>& next_microservice, vector<long long>& secret_number)
{
    vector<vector<long long>> dp(num + 1, vector<long long>(next_microservice.size() + 1, -1));

    for (int i = 0; i < dp[0].size(); i++) dp[0][i] = 0;
    
    return helper(num, microservice_id, next_microservice, secret_number, dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long size;
    cin >> size;

    vector<long long> next_microservice(size + 1, -1);
    vector<long long> secret_number(size + 1, -1);
    vector<int> parameter(2, -1);

    long long num;
    long long microservice_id;

    for (int i = 1; i <= size; i++)
    {
       for (int j = 0; j < 2; j++) cin >> parameter[j];

       next_microservice[i] = parameter[0];
       secret_number[i] = parameter[1];
    }

    for (int i = 0; i < 2; i++) cin >> parameter[i];

    num = parameter[0];
    microservice_id = parameter[1];

    std::cout << getResult(num, microservice_id, next_microservice, secret_number);
    
    return 0;
}