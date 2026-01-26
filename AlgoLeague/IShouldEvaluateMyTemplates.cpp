#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;

long long add(long long a, long long b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

vector<long long> helper(vector<long long>& array, long long counter)
{

    for (int j = 0; j < counter; ++j)
    {
            int counter = array[0];

    for (int i = 1; i < array.size(); i++)
    {
        counter += array[i];
        array[i] = counter;
    }
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long size, counter;
    cin >> size, counter;

    vector<long long> array(size, 0);
    array[0] = 1;

    helper(array, counter);

    std::cout << array.back() % MOD;

    return 0;
}