#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

long long maxWeight(vector<int>& pizzas)
{
    int size = pizzas.size();
    sort(pizzas.begin(), pizzas.end());
    int num_of_days = size / 4;
    int even = num_of_days / 2;
    int odd = num_of_days - even;
    int gain = 0;
    int index = 0;

    for (int i = 0; i < odd; i++)
    {
        gain += pizzas[size - index - 1];
        index++;
    }
    index++;

    for (int i = 0; i < even; i++)
    {
        gain += pizzas[size - index - 1];
        index += 2;
    }
    return gain;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> array = {1,2,3,4,5,6,7,8};
    std::cout << maxWeight(array) << '\n';
    
    return 0;
}