#include <bits/stdc++.h>
using namespace std;

// Sonsuz değer için güvenli bir sayı
const int INF = 1e18; 

// {Mesafe, Düğüm} tutan pair
// Pair'in ilk elemanı mesafe olmalı ki PQ ona göre sıralasın!
using pii = pair<long long, int>;

vector<long long> dijkstra(int startNode, int n, vector<vector<pii>>& adj) {
    // 1. Mesafeleri sonsuz yap
    vector<long long> dist(n + 1, INF);
    
    // 2. Min-Heap Tanımla (Küçükten büyüğe sıralar)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 3. Başlangıcı ekle
    dist[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        // OPTİMİZASYON (Çok Önemli): 
        // Eğer kuyruktan çıkan bu mesafe (d), zaten bildiğimizden (dist[u]) büyükse
        // demek ki bu çöp bir veri, daha önce daha iyisini bulmuşuz. Atla.
        if (d > dist[u]) continue;

        // Komşuları gez
        for (auto& edge : adj[u]) {
            int v = edge.first;      // Komşu
            int weight = edge.second; // Yol ağırlığı

            // RELAXATION (Gevşetme)
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}