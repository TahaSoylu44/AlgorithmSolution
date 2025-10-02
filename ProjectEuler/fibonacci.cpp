#include <iostream>

int fibonacci(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n -2);
    }


}

int main() {
    int result = 0;
    int fibo = 0;
    int counter = 0;

    while (fibo < 4000000){
        result += fibo;
        counter += 3;
        fibo = fibonacci(counter);
    }
    
    std::cout << result << std::endl;
    
    return 0;
}