#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x, y;

    cin >> x >> y;

    int max = (y > x) ? y:x;

    vector<int> arr(n + max + 1);

    arr[n + max] = 1;

    for (int i = n + max - 1; i > n; i--)
    {
        arr[i] = 0;
    }

    for (int i = n; i >= 0; i--)
    {
        arr[i] = arr[i + x] + arr[i + y];
    }

    cout << arr[0] << endl;

    return 0;
}