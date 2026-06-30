#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isReached(pair<int,int> location, pair<int,int>& destination, int day, string& forecast, int n_forecast)
{
    int plus = day % n_forecast;
    int each = day / n_forecast;

    for (char c : forecast)
    {
        if (c == 'R') location = {location.first + each, location.second};
        else if (c == 'U') location = {location.first, location.second + each};
        else if (c == 'L') location = {location.first - each, location.second};
        else if (c == 'D') location = {location.first, location.second - each};
    }

    for (int i = 0; i < plus; i++)
    {
        char a = forecast[i];
        if (a == 'R') location = {location.first + 1, location.second};
        else if (a == 'U') location = {location.first, location.second + 1};
        else if (a == 'L') location = {location.first - 1, location.second};
        else if (a == 'D') location = {location.first, location.second - 1};
    }

    int need_x = abs(destination.first - location.first);
    int need_y = abs(destination.second - location.second);

    return (need_x + need_y) <= day;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x1, y1;
    int x2, y2;
    int n_forecast;
    string forecast;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> n_forecast;
    cin >> forecast;

    if (x1 == x2 && y1 == y2)
    {
        std::cout << 0;
        return 0;
    }

    int left = 0;
    int right = 1e18;
    int ans, mid;
    ans = -1;

    pair<int,int> location = {x1,y1};
    pair<int,int> destination = {x2,y2};

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (isReached(location, destination, mid, forecast, n_forecast))
        {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    std::cout << ans;

    return 0;
}