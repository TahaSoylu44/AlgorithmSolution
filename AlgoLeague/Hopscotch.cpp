#include <iostream>

using namespace std;

int main() {
    long long n;
    long long jump;
    cin >> n >> jump;

    long long modulNumber = jump % (2 * (n - 1));
    
    if(modulNumber == 0){
        modulNumber = 2 * (n - 1);
    }
    if(modulNumber > n){
        modulNumber = (2 * n) - modulNumber;
    }

    long long rowNumber = modulNumber - 1;

    if(rowNumber % 2 == 0){
        rowNumber /= 2;
        cout << (3 * rowNumber) + 1;
    }
    else{
        rowNumber /= 2;
        cout << (3 * rowNumber) + 2 << " " << (3 * rowNumber) + 3;
    }
    
    return 0;
}