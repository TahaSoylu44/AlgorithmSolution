#include <iostream>
#include <vector>

using namespace std;

vector<int> oddNumbers(int l, int r) {
    int upperLimit;
    int lowerLimit;

    if (l % 2 != 0) lowerLimit = l;
    else lowerLimit = l + 1;

    if (r % 2 != 0) upperLimit = r;
    else upperLimit = r - 1;

    vector<int> myarr(((upperLimit - lowerLimit) / 2) + 1);

    int idx = 0;

    for (int i = lowerLimit; i <= upperLimit; i += 2)
    {
        myarr[idx] = i;
        idx++;
    }

    return myarr;
}

int main() {

    vector<int> myarr = oddNumbers(3,10);

    for (int i = 0; i < myarr.size(); i++)
    {
        std::cout << myarr[i] << " ";
    }

    return 0;
}