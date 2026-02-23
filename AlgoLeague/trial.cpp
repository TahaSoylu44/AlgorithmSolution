#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name = "taha";
    string surname = "taha";
    name[0] = 'b';

    std::cout << "name: " << name << '\n';
    std::cout << "surname: " << surname << '\n';
}