#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++) cin >> arr[i];

    int max = arr[0];
    int counter = 0;
    int element;

    for (int i = 1; i < size; i++){
        element = arr[i];

        if(element > max){
            max = element;
            counter++;
        }
    }
    
    cout << counter;

    return 0;
}