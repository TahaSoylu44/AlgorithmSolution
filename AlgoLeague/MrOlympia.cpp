#include <iostream>
#include <vector>

using namespace std;

vector<string> solve(vector<string>& array, bool& arranged)
{
    if (!arranged) return array;

    arranged = false;
    vector<string> newArray;
    int size = array.size();
    string prohibited = "";

    for (int i = 0; i < size; i++)
    {
        if (i == size) break;

        if (array[i] == prohibited)
        {
            prohibited = "";
            continue;
        }

        if (i == size - 1) 
        {
            newArray.push_back(array[i]);
            break;
        }

        if (array[i] != array[i + 1]) newArray.push_back(array[i]);
        
        else
        {
            prohibited = array[i];
            arranged = true;
        }
    }

    return solve(newArray, arranged);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    vector<string> v(size);

    for (int i = 0; i < size; i++) cin >> v[i];

    bool arranged = true;

    vector<string> result = solve(v, arranged);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    
    return 0;
}