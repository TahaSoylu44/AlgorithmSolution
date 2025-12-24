#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm> // Log2 yerine daha guvenli isler icin

using namespace std;

// Bu fonksiyonu C++'in hazir fonksiyonuyla degistirmedim ama
// pow ve log2 cok yavastir ve hatali sonuc verebilir. 
// Simdilik mantigin kalsin diye dokunmuyorum.
long long function1(long long n)
{
    long long counter = 0;
    // Güvenlik önlemi: 0 gelirse döngüye girme
    if (n <= 0) return 0;

    while (n != 0)
    {
        // Log2 ve pow yerine bit manipülasyonu çok daha iyidir ama
        // şimdilik senin kodun çalışsın diye bırakıyorum.
        long long p = (long long)log2(n);
        n -= (long long)pow(2, p);
        counter++;
    }
    return counter;
}

long long function2(long long n, long long i)
{
    return n % (i + 1);
}

long long function3(long long n)
{
    return n;
}

// DİKKAT: Dönüş tipi multimap oldu. Key artık vector!
multimap<vector<long long>, vector<long long>> sortVector(vector<vector<long long>>& keys, long long numOfKeys, long long numOfElements)
{
    // Eşit değerler silinmesin diye "multimap"
    multimap<vector<long long>, vector<long long>> myMap;

    for (long long i = 0; i < numOfKeys; i++)
    {
        vector<long long> elementArray = keys[i];
        
        // Sıralama anahtarımız artık tek bir sayı değil, bir liste!
        vector<long long> sortKey; 

        for (long long j = 0; j < numOfElements; j++)
        {
            long long element = elementArray[j];
            long long remainder = (j + 1) % 3;
            long long computedVal = 0;

            if (remainder == 1) computedVal = function1(element);
            else if (remainder == 2) computedVal = function2(element, j);
            else if (remainder == 0) computedVal = function3(element);
            
            // Matematiksel toplama yok! Listeye ekle.
            // C++ {1, 10}'un {2, 0}'dan küçük olduğunu bilir.
            sortKey.push_back(computedVal);
        }
        myMap.insert({sortKey, elementArray});
    }
    return myMap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long numOfKeys;
    long long numOfElements;

    if (!(cin >> numOfKeys >> numOfElements)) return 0;

    vector<vector<long long>> keys(numOfKeys, vector<long long>(numOfElements));

    for (long long i = 0; i < numOfKeys; i++)
    {
        for (long long j = 0; j < numOfElements; j++) cin >> keys[i][j];
    }

    // Sıralama
    multimap<vector<long long>, vector<long long>> myMap = sortVector(keys, numOfKeys, numOfElements);

    // Map zaten küçükten büyüğe sıralı.
    // Sen tersten yazdırmak istiyorsun (Büyükten küçüğe).
    // O yüzden rbegin (reverse begin) kullanıyoruz.
    
    for (auto it = myMap.rbegin(); it != myMap.rend(); ++it)
    {
        vector<long long> row = it->second;
        for (long long j = 0; j < numOfElements; j++)
        {
            cout << row[j] << (j == numOfElements - 1 ? "" : " ");
        }
        cout << '\n';
    }

    return 0;
}