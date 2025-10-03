#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int min = a[0];
    int element;
    int sum = 0;
    int size = a.size();

    for (int i = 1; i < size; i++){
        element = a[i];

        if(element < min){
            min = element;
        }
    }

    for (int i = 0; i < size; i++){
        sum += a[i];
    }

    cout << (sum - min);    
    
    return 0;
}