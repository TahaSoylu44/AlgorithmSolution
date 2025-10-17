#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x, y;

    cin >> x >> y;
    
    int num1 = 1;
    int num2 = 1;
    int tmp;

    for(int i = 0; i < n - 1; i++){
        tmp = num1;
        num1 = num1 + num2;
        num2 = tmp;
    }
    cout << num1 << endl;
    return 0;
}