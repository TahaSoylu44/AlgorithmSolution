#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool helper(vector<vector<long long>>& vectors, vector<long long>& targetVector, int a)
{
    bool isNull = true;

    for (int num : targetVector)
    {
        if (num != 0)
        {
            isNull = false;
            break;
        } 
    }

    if (isNull) return true;
    if (a == vectors.size()) return false;
    
    vector<long long> newTarget(targetVector.size());

    for (int i = 0; i < targetVector.size(); i++)
    {
        newTarget[i] = targetVector[i] - vectors[a][i];
    }

    bool opt1 = helper(vectors, newTarget, a + 1);
    bool opt2 = helper(vectors, targetVector, a + 1);

    return opt1 || opt2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long numOfVectors;
    long long numOfDimensions;

    cin >> numOfVectors >> numOfDimensions;

    vector<vector<long long>> vectors(numOfVectors, vector<long long>(numOfDimensions));

    for (int i = 0; i < numOfVectors; i++)
    {
        for (int j = 0; j < numOfDimensions; j++)
        {
            cin >> vectors[i][j];
        } 
    }

    vector<long long> targetVector(numOfDimensions);

    for (int i = 0; i < numOfDimensions; i++) cin >> targetVector[i];

    if (helper(vectors, targetVector, 0)) std::cout << "YES";
    else std::cout << "NO";
    
    return 0;
}