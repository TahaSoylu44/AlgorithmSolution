#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    // Eğer iki makinedeki sayılar zaten eşitse
    if (a == b) {
        // Eğer sayı 1'den büyükse x=0 yeterlidir, aksi halde 2'ye tamamlarız
        if (a > 1) cout << 0 << '\n';
        else cout << 2 - a << '\n';
        return 0;
    }

    int D = abs(a - b);

    // Ardışık sayıların ortak böleni yoktur
    if (D == 1) {
        cout << -1 << '\n';
        return 0;
    }

    int min_x = 2e18; // Sonsuzluk
    int temp = D;

    // D'nin asal çarpanlarını buluyoruz
    for (int i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            // i bir asal çarpandır, gereken x'i hesapla
            int x = (i - (a % i)) % i;
            min_x = min(min_x, x);
            
            // i'nin diğer kuvvetlerini temizle
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }

    // Eğer temp 1'den büyük kaldıysa, kendisi de bir asal sayıdır
    if (temp > 1) {
        int x = (temp - (a % temp)) % temp;
        min_x = min(min_x, x);
    }

    cout << min_x << '\n';

    return 0;
}