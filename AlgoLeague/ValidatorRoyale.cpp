#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

bool isValid(vector<string>& array)
{
    if (array.size() == 0) return true;

    map<string, pair<long long,long long>> mymap;
    string card;

    for (long long i = 0; i < array.size(); i++)
    {
        card = array[i];

        if (mymap.count(card))  // kart zaten var
        {
            if (mymap[card].first == i)  // mirror olarak geldi  
            {
                //
            } 

            else if (mymap[card].second <= i)   // uygun bir yerde ve mirror değil
            {
                mymap[card].first = i + 1;  // mirror gelebilir
                mymap[card].second = i + 5; // available konum güncelle
            }
            else return false;  // yeri yanlış
        }
        else    // kart ilk defa geldi
        {
            mymap[card] = {i + 1, i + 5};   // kart eklendi

            if (mymap.size() > 8) return false; // 8 çeşitten fazla kart var
        }
    }
    return true;    // hiç false görmedi
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long size;
    cin >> size;

    vector<string> array(size);

    for (long long i = 0; i < size; i++) cin >> array[i];

    bool valid = isValid(array);

    if (valid) std::cout << "VALID";
    else std::cout << "INVALID";
    
    return 0;
}