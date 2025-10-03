#include <iostream>

using namespace std;

int main() {
    
    int numOfchild;
    int numOfcandy;

    cin >> numOfchild;
    
    int candy[numOfchild];
    for(int i = 0;i < numOfchild;i++) cin >> candy[i];

    cin >> numOfcandy;
    
    int max = candy[0];
    int element;
    int neededSugar = 0;
    int need;

    for (int i = 0; i < numOfchild; i++){
        element = candy[i];

        if(element > max){
            max = element;
        }
    }

    for (int i = 0; i < numOfchild; i++){
        need =  max - candy[i];
        neededSugar += need;
    }

    if(neededSugar > numOfcandy){
        cout << 0;
    }
    else{
        if((numOfcandy - neededSugar) % numOfchild == 0){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    
    return 0;
}