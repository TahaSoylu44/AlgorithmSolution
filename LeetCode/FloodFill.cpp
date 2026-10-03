#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

void recur(vector<vector<int>>& image, int sr, int sc, int color, vector<int>& dx, vector<int>& dy, int starting)
{
    int m = image.size();
    int n = image[0].size();

    if ((sr < 0) || (sr >= m)) return;
    if ((sc < 0) || (sc >= n)) return;
    if (image[sr][sc] == color) return;
    if (image[sr][sc] != starting) return;

    image[sr][sc] = color;
    for (int i = 0; i < 4; i++) recur(image, sr + dx[i], sc + dy[i], color, dx, dy, starting);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    vector<int> dx = {0,1,-1,0};
    vector<int> dy = {1,0,0,-1};
    recur(image, sr, sc, color, dx, dy, image[sr][sc]);
    return image;
}

void print(vector<vector<int>>& array)
{
    if (array.empty()) return;

    for (vector<int> v : array)
    {
        for (int num : v) std::cout << num << " ";
        std::cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> array = {{1,1,1}, {1,1,0}, {1,0,1}};
    vector<vector<int>> result = floodFill(array, 1, 1, 2);
    print(result);
    
    return 0;
}