#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> setArray(vector<int> windows)
{
    int size = windows.size();
    for (int i = size - 2; i >= 1; i--)
    {
        if (windows[i] > windows[i+1]) {
            windows[i] = windows[i+1];
        }
    }
    return windows;
}

void minValue(vector<int>& array)
{
    int size = array.size();

    vector<int> windows(size + 1, 1000000000);
    
    vector<int> leftArray(size);
    vector<int> rightArray(size);
    stack<int> s; 

    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && array[s.top()] <= array[i])
        {
            s.pop();
        }
        
        if (s.empty())
        {
            leftArray[i] = -1;   
        }
        else
        {
            leftArray[i] = s.top(); 
        }
        s.push(i); 
    }

    while (!s.empty()) s.pop(); 
    
    for (int i = size - 1; i >= 0; i--)
    {
        while (!s.empty() && array[s.top()] <= array[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            rightArray[i] = size; 
        }
        else
        {
            rightArray[i] = s.top(); 
        }  
        s.push(i); 
    }

    for (int i = 0; i < size; i++)
    {
        int len = rightArray[i] - leftArray[i] - 1;

        if (array[i] < windows[len]) windows[len] = array[i];
    }

    windows = setArray(windows);

    for (int i = 1; i < size + 1; i++)
    {
        std::cout << windows[i] << '\n'; 
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    vector<int> array(size);
    for (int i = 0; i < size; i++) cin >> array[i];

    minValue(array);

    return 0;
}