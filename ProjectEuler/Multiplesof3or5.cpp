#include <iostream>

int sum(int n){return 0.5 * n * (n + 1);}

int main() {
    
    int until3 = 1000 / 3;
    int until5 = (1000 / 5) - 1;
    int until15 = 1000 / 15;

    int result = 3 * sum(until3) + 5 * sum(until5) - 15 * sum(until15);
    std::cout << result<< std::endl;

    return 0;
}