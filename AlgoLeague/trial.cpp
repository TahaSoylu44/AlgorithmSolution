#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numOfDumbells;
    int numOfQuery;
    int num1;
    int num2;
    int result;
    int add = 0;

    vector<int> queries(2);
    vector<int> sum;

    cin >> numOfDumbells >> numOfQuery;
    
    vector<int> dumbells(numOfDumbells);

    for(int i = 0; i < numOfDumbells; i++) cin >> dumbells[i];

    for(int i = 0; i < numOfQuery; i++){
        cin >> num1 >> num2;

        if(num2 <= sum.size()){
            if(num1 == 1){
                cout << sum[num2 - 1] << endl;
            }
            else{
                cout << sum[num2 - 1] - sum[num1 - 2] << endl;
            }
        }
        else{
            for(int i = 0; i < num2; i++){
                add += dumbells[i];

                if(find(sum.begin(), sum.end(), add) == sum.end()){
                    sum.push_back(add);
                }
            }
            add = 0;

            if(num1 == 1){
                cout << sum[num2 - 1] << endl;
            }
            else{
                cout << sum[num2 - 1] - sum[num1 - 2] << endl;
            }
        }
    }

    return 0;
}