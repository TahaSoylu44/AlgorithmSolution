#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int solve(vector<int>& numbers)
{
    int left = 0;
    int right = numbers.size() - 1;
    int value = 0;

    while (left < right)
    {
        value += (numbers[left] * numbers[right]);
        left++;
        right--;
    }
    return value;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int a;
    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }

    sort(numbers.begin(), numbers.end());
    std::cout << solve(numbers) << '\n';
    
    return 0;
}