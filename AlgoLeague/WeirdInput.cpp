#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    char c;

    string s;

    for (int i = 0; i < size; i++)
    {
        cin >> c;
        s += c;
    }

    long long number = stoll(s);

    std::cout << 2 * number;
    
    return 0;
}