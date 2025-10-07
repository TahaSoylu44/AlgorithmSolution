#include <iostream>

using namespace std;

int main() {
    int counter1 = 0;
    int counter2 = 0;

    for (int i = 1; i < 101; i++){
        counter1 += i * i;
    }

    for (int i = 1; i < 101; i++){
        counter2 += i;
    }

    counter2 = counter2 * counter2;

    if(counter2 > counter1){
        cout << counter2 - counter1 << endl;
    }
    else{
        cout << counter1 - counter2 << endl;
    }

    return 0;
}