#include <iostream>
#include <vector>

using namespace std;

int main() {
    int coinSize;
    int wanted;
    int counter = 0;
    bool isEven = false;
    int number = 1;
    int need;

    cin >> coinSize >> wanted;

    vector<int> arr(coinSize);

    // for (int i = 0; i < coinSize; i++) cin >> arr[i];

    //k = 1
    for (int i = 0; i < coinSize; i++)
    {
        if(wanted % number == 0){
            isEven = true;
        }
        if(isEven == 1){
            need = wanted / number;

            if(need <= arr[number - 1]){
                counter++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}