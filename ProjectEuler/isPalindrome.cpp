#include <iostream>
#include <string>
#include <chrono>

bool isPalindrome(std::string n){
    int length = n.length();

    int stop = length / 2;

    for (int i = 0; i < stop; i++){
        if(n.at(i) == n.at(length - 1 - i)){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

bool isTwo(int n){
    bool isEven = (n % 2 == 0) ? true : false;
    int result;

    if(isEven == 1){
        for (int i = 100; i < 999; i += 2){
            if(n % i == 0){
                result = n / i;

                if(result > 99 && result < 1000){
                    return true;
                }
            }
        }
        return false;
        
    }
    else{
        for (int i = 101; i < 1000; i += 2){
            if(n % i == 0){
                result = n / i;

                if(result > 99 && result < 1000){
                    return true;
                }
            }
        }
        return false;
    }
}

int detect(){
    std::string s;
    
    for (int i = 998001; i >= 10000; i--){
        s = std::to_string(i);

        if(isPalindrome(s) == 1){
            if(isTwo(i)){
                return i;
            }
        }
    }
    return 0;
}

int main() {
    //START
    auto start = std::chrono::high_resolution_clock::now();
    
    std::cout << detect() << std::endl;

    //END
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "The duration: " << duration.count() << std::endl;

    return 0;
}