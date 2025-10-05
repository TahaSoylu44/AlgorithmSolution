#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std;

void zeros(vector<string> &arr){
    int flag = 0;
    int quotient = 2;
    int counter = 0;
    int size = arr.size();

    while(quotient < size){
        for (int i = 0; i < size; i++){
            if(flag == 0){
                arr[i] = "0" + arr[i];
                counter++;

                if(counter == quotient){
                    flag = 1;
                    counter = 0;
                }
            }
            else{
                arr[i] = "1" + arr[i];
                counter++;

                if(counter == quotient){
                    flag = 0;
                    counter = 0;
                }
            }
        } 
        quotient *= 2;
    }
}

int main() {

    int n;
    cin >> n;
    
    //START
    auto start = chrono::high_resolution_clock::now();

    int size = pow(2, n);
    vector<string> arr(size, " ");

    for (int i = 0; i < size; i++){
        if(i % 2 == 0){
            arr[i] = "0";
        }
        else{
            arr[i] = "1";
        }
    }

    zeros(arr);

    for (int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

    //END
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    std::cout << "The duration: " << duration.count() << std::endl;
    
    return 0;
}