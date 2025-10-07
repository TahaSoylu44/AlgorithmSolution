#include <iostream>

using namespace std;

long long sticker(long long n){
    long long a;
    long long b;
    if(n == 0){
        return 1;
    }
    else if(n < 10){
        return n;
    }
    else{
        a = n / 10;
        b = n % 10;

        return sticker(a) * sticker(b);
    }
}

int main() {
    long long n;

    cin >> n;

    while(n > 9){
        n = sticker(n);
    }

    cout << n << endl;

    return 0;
}