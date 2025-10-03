#include <iostream>
#include <cmath>
#include <stdint.h>

bool isPrime(uint64_t n){
    double root;
    if(n > 1){
        if (n == 2){
            return true;
        }
        else if(n % 2 == 0){
            return false;
        }
        else{
            root = sqrt(n);
            for (int i = 3; i < root; i += 2){
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

int detect(){
    uint64_t qouitent;
    uint64_t number = 600851475143ULL;

    for (uint64_t i = 3; i <= 300425737571ULL; i += 2){
        if(number % i == 0){
            qouitent = number / i;

            if(isPrime(qouitent) == 1){
                return qouitent;
            }
        }
        else{
            continue;
        }
    }
    return 0;
}

int main(){

    std::cout << detect();

    return 0;
}