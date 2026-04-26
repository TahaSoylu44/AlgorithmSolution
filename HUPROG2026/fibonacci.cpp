#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

string string_sum(string a, string b)
{
    int elde = 0;
    int result = 0;
    string son = "";
    int i = 0;

    for (; i < min(a.size(), b.size()); i++)
    {
        result = (a[a.size() - 1 - i] - '0') + (b[b.size() - 1 - i] - '0') + elde;
        son.push_back((result % 10) + '0');
        elde = result / 10;
    }

    for (int j = i; j < a.size(); j++)
    {
        result = (a[a.size() - j - 1] - '0') + elde;
        son.push_back((result % 10) + '0');
        elde = result / 10;
    }

    for (int j = i; j < b.size(); j++)
    {
        result = (b[b.size() - j - 1] - '0') + elde;
        son.push_back((result % 10) + '0');
        elde = result / 10;
    }

    if (elde > 0) son.push_back(elde + '0');

    string result_string = "";
    for (int i = son.size() - 1; i >= 0; i--) result_string.push_back(son[i]);

    return result_string;
}

string fibonacci(string n)
{
    if (n == "1" || n == "2") return "1";

    int int_n = stoi(n);

    vector<string> array(int_n);
    array[0] = array[1] = "1";

    for (int i = 2; i < int_n; i++) array[i] = string_sum(array[i - 1], array[i - 2]);
    return array.back();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string n;
    cin >> n;
    std::cout << fibonacci(n);
    
    return 0;
}