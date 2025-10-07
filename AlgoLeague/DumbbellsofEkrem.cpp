#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numOfDumbells;
    int numOfQuery;
    int counter = 0;
    int result = 0;
    int index1;
    int index2;

    int firstLine[2];
    for(int i = 0; i < 2; i++) cin >> firstLine[i];

    numOfDumbells = firstLine[0];
    numOfQuery = firstLine[1];
    
    vector<int> dumbells(numOfDumbells);
    vector<int> queries(2 * numOfQuery);

    for(int i = 0; i < numOfDumbells; i++) cin >> dumbells[i];

    while(counter < numOfQuery){
        for(int i = 0; i < 2; i++) cin >> queries[i];

        index1 = queries[0] - 1;
        index2 = queries[1] - 1;

        for (int i = index1; i <= index2; i++){
            result += dumbells[i];
        }

        cout << result << endl;
        
        result = 0;
        counter++;
    }

    return 0;
}