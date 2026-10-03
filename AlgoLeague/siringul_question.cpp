#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

struct Wave
{
    int distance;
    int velocity;
    int amplitude;
};

double catch_it(Wave& w1, Wave& w2) 
{
    double d_yol = w1.distance - w2.distance;
    double d_zaman = w1.velocity - w2.velocity;

    if (d_zaman == 0) return 0;
    return d_yol / d_zaman;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<double,int> location_to_value;
    vector<double> durations;

    int n; cin >> n;
    vector<Wave> waves(n);
    int d, v, a;
    double duration;
    Wave wave;
    int maximum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> d >> v >> a;
        wave = {d,v,a};
        waves[i] = wave;
        location_to_value[d] += a;
        maximum = max(maximum, location_to_value[d]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            duration = catch_it(waves[i], waves[j]);
            if (duration > 0) durations.push_back(duration);
        }
    }

    sort(durations.begin(), durations.end());
    durations.erase(unique(durations.begin(), durations.end()), durations.end());
    double position;

    for (double time : durations)
    {
        map<double,int> location_to_value;

        for (Wave& wave : waves)
        {
            position = wave.distance - (time * wave.velocity);
            if (position > 0) location_to_value[position] += wave.amplitude;
        }

        for (auto& [key,value] : location_to_value) maximum = max(maximum, value);
    }

    std::cout << maximum << '\n';
    
    return 0;
}