#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

void printVector(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> merge(vector<int> left, vector<int> right){
    int k = 0;
    int left_element;
    int right_element;
    vector<int> merged;
    int totalSize = left.size() + right.size();

    for (int i = 0; i < totalSize; i++)
    {
        if(k >= right.size()){
            merged.push_back(left[i]);

            if(merged.size() == totalSize){
                counter++;
                return merged;
            }
        }
        else if(i >= left.size()){
            merged.push_back(right[k]);
            k++;

            if(merged.size() == totalSize){
                counter++;
                return merged;
            }
        }
        else{
            left_element = left[i];
            right_element = right[k];

            if(left_element <= right_element){
                merged.push_back(left_element);
            }
            else{
                merged.push_back(right_element);
                k++;
                i--;
            }
        }
    }
    return merged;
}

vector<int> mergeSort(vector<int> arr){
    int size = arr.size();
    int pivot;

    if(size == 1){
        return arr;
    }
    else{
        if(size % 2 == 0){
            pivot = (size / 2) - 1;
        }
        else{
            pivot = size / 2;
        }

        vector<int> left;
        vector<int> right;

        for (int i = 0; i < size; i++)
        {
            if (i <= pivot){
                left.push_back(arr[i]);
            }
            else{
                right.push_back(arr[i]);
            }
        }
        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
}

int main() {
    int size;
    cin >> size;

    vector<int> v1(size);

    for(int i = 0; i < size; i++) cin >> v1[i];

    vector<int> sorted = mergeSort(v1);

    printVector(sorted);
    cout << " " << endl;
    cout << counter;

    return 0;
}