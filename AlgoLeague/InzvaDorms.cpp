#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numOfRooms, numOfParticipants;
    cin >> numOfRooms >> numOfParticipants;

    vector<int> rooms(numOfRooms);
    for (int i = 0; i < numOfRooms; i++) cin >> rooms[i];

    vector<int> pariticipants(numOfParticipants);
    for (int i = 0; i < numOfParticipants; i++) cin >> pariticipants[i];

    for (int i = 1; i < numOfRooms; i++) rooms[i] = rooms[i - 1] + rooms[i];
    
    for (int member : pariticipants)
    {
        if (member > rooms.back()) std::cout << -1 << '\n';
        else
        {
            auto it = lower_bound(rooms.begin(), rooms.end(), member);
            std::cout << it - rooms.begin() + 1 << '\n';
        }
    }
    
    return 0;
}