#include <iostream>
#include <chrono>

using namespace std;

int main() {
    int size;
    string s;
    char c;
    int counter = 1;
    string answer = "";

    cin >> size;
    char arr[size];
    cin >> s;

    //START
    auto start = chrono::high_resolution_clock::now();

    arr[0] = s.at(0);

    for (int i = 1; i < s.length(); i++){
        c = s.at(i);

        if(arr[counter - 1] == c){
            continue;
        }
        else{
            arr[counter] = c;
            counter++;
        }
    }

    for (int i = counter; i < size; i++){
        arr[i] = ' ';
    }
    
    for (int i = 0; i < size; i++){
        if(arr[i] == ' '){
            break;
        }
        else{
            answer += arr[i];
        }
    }

    cout << answer;

    //END
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    std::cout << "The duration: " << duration.count() << std::endl;
}