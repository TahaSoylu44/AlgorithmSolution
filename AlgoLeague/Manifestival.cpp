#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

const int INF = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    int s, f, d;

    vector<int> bus_stops = {-INF, 0};
    for (int i = 0; i < N - 1; i++)
    {
        cin >> d;
        bus_stops.push_back(bus_stops.back() + d);
    }
    bus_stops.push_back(INF);

    int s_left_idx;
    int s_right_idx;
    int f_left_idx;
    int f_right_idx;
    int s_left;
    int s_right;
    int f_left;
    int f_right;
    int min_energy;

    while (Q--)
    {
        cin >> s >> f;
        min_energy = 2 * abs(s - f);

        // s.left -> f.left  s.right -> f.left  s.left -> f.right  s.right -> r.fight

        s_left_idx = (upper_bound(bus_stops.begin(), bus_stops.end(), s)) - bus_stops.begin() - 1;
        s_right_idx = (upper_bound(bus_stops.begin(), bus_stops.end(), s) - bus_stops.begin());
        f_left_idx = (upper_bound(bus_stops.begin(), bus_stops.end(), f)) - bus_stops.begin() - 1;
        f_right_idx = (upper_bound(bus_stops.begin(), bus_stops.end(), f) - bus_stops.begin());

        s_left = bus_stops[s_left_idx];
        s_right = bus_stops[s_right_idx];
        f_left = bus_stops[f_left_idx];
        f_right = bus_stops[f_right_idx];

        min_energy = min(min_energy, 2 * abs(s - s_left) + abs(f_left - s_left) + 2 * abs(f - f_left));
        min_energy = min(min_energy, 2 * abs(s - s_right) + abs(f_left - s_right) + 2 * abs(f - f_left));
        min_energy = min(min_energy, 2 * abs(s - s_left) + abs(f_right - s_left) + 2 * abs(f - f_right));
        min_energy = min(min_energy, 2 * abs(s - s_right) + abs(f_right - s_right) + 2 * abs(f - f_right));

        std::cout << min_energy << '\n';
    }
    
    return 0;
}