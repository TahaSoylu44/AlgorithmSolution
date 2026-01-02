#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> array = {1,2,3,4};

    array.erase(array.begin() + 2);

    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    
    
    return 0;
}