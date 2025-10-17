#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numOfDumbells;
    int numOfQuery;
    int num1;
    int num2;

    cin >> numOfDumbells >> numOfQuery;
    
    vector<int> dumbells(numOfDumbells);
    vector<int> sum(numOfDumbells);

    for(int i = 0; i < numOfDumbells; i++) cin >> dumbells[i];

    sum[0] = dumbells[0];

    for (int i = 1; i < numOfDumbells; i++)
    {
        sum[i] = sum[i - 1] + dumbells[i];
    }

    for (int i = 0; i < numOfQuery; i++)
    {
        cin >> num1 >> num2;

        if(num1 == 1){
            cout << sum[num2 - 1] << endl;
        }
        else{
            cout << sum[num2 - 1] - sum[num1 - 2] << endl;
        }
    }
    
    return 0;
}