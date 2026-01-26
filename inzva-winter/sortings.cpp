#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

void bubble(vector<int>& v) // O(N^2)
{
    int size = v.size();
    int tmp;
    bool flag;

    for (int son = size - 1; son > 1; son--)
    {
        flag = false;   // optimization

        for (int i = 0; i < son; i++)
        {
            if (v[i] > v[i + 1])
            {
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;

                flag = true;
            }
        }

        if (!flag) return;  // hiç değişiklik olmadıysa dur
    }
}

void insertion(vector<int>& v)  // O(N^2)
{
    int size = v.size();

    for (int i = 1; i < size; i++)
    {
        int j = 0;

        for (; j < i; j++)
        {
            if (v[j] > v[i])
            {
                break;
            }
        }
        while (j < i)
        {
            swap(v[i], v[j]);
            j++;
        }
    }
}

void selection(vector<int>& v)  // recursion and iteration
{
    //
}

void merge(vector<int>& v)
{
    //
}

int main() {
    vector<int> v = {1, 5, 7, 8, 12, 11, 9};

    insertion(v);

    print(v);

    return 0;
}