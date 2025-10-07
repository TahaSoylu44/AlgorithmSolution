#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

bool isPrime(int n){
    int root = sqrt(n);

    if(n > 1){
        if(n == 2){
            return true;
        }
        else if(n % 2 == 0){
            return false;
        }
        else{
            for (int i = 3; i <= root; i += 2){
                if(n % i == 0){
                    return false;
                }
            }
            return true;
        }
    }
    else{
        return false;
    }
}

int main() {

    //START
    auto start = chrono::high_resolution_clock::now();

    int counter = 0;
    int num;

    for (int i = 3; counter < 1000000; i += 2){
        if(isPrime(i) == 1){
            num = i;
            counter++;
        }
        else{
            continue;
        }
    }

    cout << num << endl;

    //END
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    std::cout << "The duration: " << duration.count() << std::endl;

    return 0;
}