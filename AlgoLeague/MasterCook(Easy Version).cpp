#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> chefM(size);
    vector<int> chefB(size);

    for (int i = 0; i < size; i++) cin >> chefM[i];
    for (int i = 0; i < size; i++) cin >> chefB[i];

    

    return 0;
}