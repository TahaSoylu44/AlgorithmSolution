#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int i, int j)
{
    int pivot = arr[i];

    while (i < j)
    {
        do
        {
            i++;
        } while (pivot < arr[i]);

        do
        {
            j--;
        } while (arr[j] <= pivot);

        if (i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    return j;
}

void quicksort(vector<int> &arr, int i, int j)
{
    if (i >= j) return;

    int low = i;
    int high = j;

    j = partition(arr, low, high);

    quicksort(arr, low, j);
    quicksort(arr, j + 1, high);
}

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

long angryChildren(int k, vector<int> packets) {

}

int main() {

    vector<int> myarr = {1, 3, 8, 5, 2, 11, 7};
    printVector(myarr);

    quicksort(myarr, 0, myarr.size());

    printVector(myarr);

    return 0;
}