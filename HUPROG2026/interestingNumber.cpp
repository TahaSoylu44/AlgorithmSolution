#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

class Selection
{
    public:
        string number;
        int total_digit;
        int kalan;
};

string solve(int n)
{
    queue<Selection> q;
    Selection selection;
    selection.number = "";
    selection.total_digit = 0;
    selection.kalan = 0;
    char c;
    vector<vector<bool>> visited(n, vector<bool>(n + 1, false));
    Selection newSelection;

    for (int i = 1; i < 10; i++)
    {
        c = i + '0';
        newSelection.number = selection.number;
        newSelection.number.push_back(c);
        newSelection.total_digit = selection.total_digit + i;
        newSelection.kalan = (10 * selection.kalan + i) % n;
        visited[newSelection.kalan][newSelection.total_digit] = true;

        q.push(newSelection);
    }

    while (!q.empty())
    {
        selection = q.front();
        q.pop();

        if (selection.total_digit == n && selection.kalan == 0) return selection.number;

        for (int i = 0; i < 10; i++)
        {
            c = i + '0';
            newSelection.number = selection.number;
            newSelection.number.push_back(c);
            newSelection.total_digit = selection.total_digit + i;
            newSelection.kalan = (10 * selection.kalan + i) % n;

            if (newSelection.total_digit > n) continue;
            if (!visited[newSelection.kalan][newSelection.total_digit]) q.push(newSelection);
            visited[newSelection.kalan][newSelection.total_digit] = true;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    std::cout << solve(n);
    
    return 0;
}