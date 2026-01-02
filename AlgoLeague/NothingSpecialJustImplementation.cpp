#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph
{
    private:
        int v;
        vector<unordered_set<int>> adj;

    public:
        Graph(int v) {
            this->v = v;
            adj.resize(v);
        }

        void addEdge(int a, int b) {
            adj[a].insert(b);
            adj[b].insert(a);
        }

        void removeEdge(int a, int b) {
            adj[a].erase(b);
            adj[b].erase(a);
        }

        // --- YENİ ZEKİ BFS ---
        // u'dan başlayıp x veya y'ye ulaşabiliyor muyuz ona bakar.
        // Tüm grafı saymaz, sadece 'u'nun olduğu adayı boyar.
        bool checkConnectivity(int startNode, int target1, int target2) {
            
            queue<int> q;
            q.push(startNode);
            
            // Tüm visited dizisini false yapmaya gerek yok, 
            // set veya map ile gezilenleri tutmak daha hızlı olabilir (Graph çok büyük değilse)
            // Ama en temizi vector<bool> dur yine de.
            vector<bool> visited(v, false);
            visited[startNode] = true;
            
            bool foundT1 = false;
            bool foundT2 = false;

            // Başlangıç düğümü hedef olabilir mi?
            if (startNode == target1) foundT1 = true;
            if (startNode == target2) foundT2 = true;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                // Eğer iki hedefi de bulduysak aynı adadalar demektir, ERKEN ÇIKIŞ!
                if (foundT1 && foundT2) return false; 

                for(int neighbor : adj[curr]) {
                    if(!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);

                        if (neighbor == target1) foundT1 = true;
                        if (neighbor == target2) foundT2 = true;
                    }
                }
            }
            
            // Döngü bitti. 
            // Biri bulundu, diğeri bulunamadıysa -> Farklı adalardalar -> YES
            // İkisi de bulunduysa -> Aynı adadalar -> NO
            // İkisi de bulunamadıysa -> (startNode u idi, demek ki x ve y v tarafında) -> Aynı adadalar -> NO
            
            // XOR Mantığı: (Biri True, Biri False olmalı)
            return foundT1 != foundT2;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numOfNodes;
    if (!(cin >> numOfNodes)) return 0;

    Graph graph(numOfNodes + 1);

    int a, b;
    for (int i = 0; i < numOfNodes - 1; i++) {
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    int numOfQueries;
    cin >> numOfQueries;

    int u, v_node, x, y; // v değişken adını v_node yaptım karışmasın

    for (int i = 0; i < numOfQueries; i++) {
        cin >> u >> v_node >> x >> y;

        // 1. Kenarı Sil
        graph.removeEdge(u, v_node);

        // 2. Kontrol Et: u'dan başlayınca x ve y'nin durumu ne?
        // x ve y farklı parçalara düşerse bu iş olur!
        if (graph.checkConnectivity(u, x, y)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        // 3. Kenarı Geri Ekle (Backtrack)
        // Soruda "kalıcı olarak değişiyor" demiyorsa, her sorgu bağımsızsa
        // eski haline getirmen lazım. Senin kodunda öyleydi.
        graph.addEdge(u, v_node);
    }
    
    return 0;
}