#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
    int counter = 1;
    
    for (int i = 2; i <= n; i++) counter *= i;
    return counter;
}

void search(vector<int>& permutation, vector<bool>& chosen, int size)
{
    if (permutation.size() == factorial(size)) return;

    for (int i = 0; i < size; i++)
    {
        if (chosen[i]) continue;
        chosen[i] = true;
        permutation.push_back(i);
        search(permutation, chosen, size);
        chosen[i] = false;
        permutation.pop_back();
    }
}

int main() {

    int size = 5;

    vector<int> permutation;
    vector<bool> chosen(size, false);

    search(permutation, chosen, size);

    for (int i = 0; i < permutation.size(); i++)
    {
        std::cout << permutation[i] << '\n';
    }
    
    return 0;
}