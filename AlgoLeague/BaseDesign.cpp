#include <iostream>
#include <algorithm>

using namespace std;

void helper(long long a, long long b, long long x, long long y)
{
    long long case1 = a * (b - y - 1);
    long long case2 = x * b;
    long long case3 = a * y;
    long long case4 = (a - x - 1) * b;

    long long max1 = max(case1, case2);
    long long max2 = max(case3, case4);
    long long result = max(max1, max2);

    std::cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numOfQuery;
    cin >> numOfQuery;

    long long a,b,x,y;

    for (int i = 0; i < numOfQuery; i++)
    {
        cin >> a >> b >> x >> y;
        helper(a, b, x, y);
    }
    
    return 0;
}