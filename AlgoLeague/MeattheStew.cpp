#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, wanted; cin >> n >> wanted;
    
    vector<int> a_s(n), t_s(n);
    for (int i = 0; i < n; i++) cin >> a_s[i];
    for (int i = 0; i < n; i++) cin >> t_s[i];

    priority_queue<int> pq_gel;
    priority_queue<int> pq_cozun;

    for (int i = 0; i < n; i++) 
    {
        pq_gel.push(-a_s[i]);
        pq_cozun.push(-(a_s[i] + t_s[i]));
    }

    int unfrozen = 0;
    int frozen = 0;
    int time = 0; 

    while (true) {
        if (unfrozen + frozen == wanted) 
        {
            std::cout << time << '\n';
            return 0;
        }
        else if (unfrozen + frozen > wanted) 
        {
            std::cout << -1 << '\n';
            return 0;
        }

        if (unfrozen == 0) 
        {
            int next_event = 1e18; 
            if (!pq_gel.empty()) next_event = min(next_event, -pq_gel.top());
            if (!pq_cozun.empty()) next_event = min(next_event, -pq_cozun.top());
            
            if (next_event > time) time = next_event;
            else time++;
        } 
        else time++;

        while ((!pq_cozun.empty()) && (time == -pq_cozun.top())) {
            pq_cozun.pop();
            frozen--;
            unfrozen++;
        }

        while ((!pq_gel.empty()) && (time == -pq_gel.top())) {
            pq_gel.pop();
            frozen++;
        }

        unfrozen *= 2;
    }
    
    return 0;
}