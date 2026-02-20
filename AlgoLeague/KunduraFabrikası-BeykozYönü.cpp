#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

// 1.5 Milyon'a kadar tarıyoruz ki ilk 100.000 asal sayıyı kesin bulalım
vector<int> prime_list;
void sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p)
                is_prime[i] = false;
        }
    }
    // Asalları listeye topla (O(1) erişim için)
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) prime_list.push_back(p);
    }
}

int fastExp(int a, int b) {
    a = a % MOD;
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

// Modüler Ters Alma Fonksiyonu (Fermat)
int modInverse(int n) {
    return fastExp(n, MOD - 2);
}

void solve(vector<int>& values, map<int, pair<int, int>>& primeMap, string& s, int numOfmachine) {
    int value = 1;
    
    // String'i sağdan sola geziyoruz. Asal listesindeki indeximiz de 0'dan başlıyor.
    int p_idx = 0; 
    for (int i = s.size() - 1; i >= 0; i--) {
        int numberOfPrime = s[i] - '0';
        int currentPrime = prime_list[p_idx]; // Şak diye O(1)'de çektik
        
        value = (value * fastExp(currentPrime, numberOfPrime)) % MOD;

        // Sadece kuvvet 0'dan büyükse veya takip edilmesi gerekiyorsa
        if (primeMap.count(currentPrime)) {
            primeMap[currentPrime].first++;
            primeMap[currentPrime].second = min(primeMap[currentPrime].second, numberOfPrime);
        } else {
            primeMap.insert({currentPrime, {1, numberOfPrime}});
        }
        p_idx++;
    }
    values.push_back(value);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numOfmachine;
    cin >> numOfmachine;

    // Sınırı 1.5 milyon yaptık. Yaklaşık 114 bin asal çıkar.
    sieve(1500000); 

    map<int, pair<int, int>> primeMap;
    vector<int> values;

    for (int i = 0; i < numOfmachine; i++) {
        string s;
        cin >> s;
        solve(values, primeMap, s, numOfmachine);
    }

    // Ortak Kapasite (EBOB) Hesaplama
    int container = 1;
    for(auto const& [key, val] : primeMap) {
        // Eğer bu asal bütün makinelerde ortaksa, minimum üssünü al
        if (val.first == numOfmachine) {
            container = (container * fastExp(key, val.second)) % MOD;
        }
    }

    // ÇÖZÜM: Bölme yerine Modüler Ters ile çarpıyoruz!
    int numOfContainer = 0;
    int invContainer = modInverse(container); // Sadece bir kere hesaplamak yeterli

    for (int num : values) {
        // (X / EBOB) % MOD  === (X * EBOB_INVERSE) % MOD
        int currentContainers = (num * invContainer) % MOD;
        numOfContainer = (numOfContainer + currentContainers) % MOD;
    }

    std::cout << numOfContainer << '\n';
    
    return 0;
}