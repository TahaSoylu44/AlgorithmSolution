#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void presum_made(vector<int>& array)
{
    for (int i = 1; i < array.size(); i++) array[i] += array[i - 1];
}

int solve(vector<int>& deadlift, vector<int>& bench, int numOfDeadLift, int numOfBench)
{
    auto it1 = lower_bound(deadlift.begin(), deadlift.end(), numOfDeadLift);
    auto it2 = lower_bound(bench.begin(), bench.end(), numOfBench);

    if (it1 == deadlift.end() || it2 == bench.end()) return -1;

    int day_deadLift = it1 - deadlift.begin();
    int day_bench = it2 - bench.begin();

    return max(day_deadLift, day_bench) + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, numOfquestions;
    cin >> n >> numOfquestions;

    vector<int> deadlift(n);
    vector<int> bench(n);

    for (int i = 0; i < n; i++) cin >> deadlift[i];
    for (int i = 0; i < n; i++) cin >> bench[i];

    presum_made(deadlift);
    presum_made(bench);

    int x, y;

    for (int i = 0; i < numOfquestions; i++)
    {
        cin >> x >> y;
        std::cout << solve(deadlift, bench, x, y) << '\n';
    }
    
    return 0;
}