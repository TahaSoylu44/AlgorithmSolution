#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> number(1000, 0);

    number[0] = 1;
    
    int size = 1; 

    for (int j = 0; j < 1000; j++)
    {
        int carry = 0; 
        for (int i = 0; i < size; i++)
        {
            int value = number[i] * 2 + carry;

            number[i] = value % 10;
            carry = value / 10;     
        }

        while (carry > 0)
        {
            number[size] = carry % 10;
            carry /= 10;
            size++; 
        }
    }
    int sum = 0;
    std::cout << "Sayi (Ters): ";
    for (int i = 0; i < size; i++) {
        sum += number[i];
        std::cout << number[i]; 
    }
    
    std::cout << "\n\nRakamlar Toplami: " << sum << endl;
    
    return 0;
}