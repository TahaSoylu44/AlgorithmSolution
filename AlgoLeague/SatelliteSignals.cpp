#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isIn(long long n, vector<long long> arr){
    for (long long i = 0; i < arr.size(); i++)
    {
        if (arr[i] == n)
        {
            return true;
        } 
    }
    return false;
}

bool isPrime(long long n){
    long long sqr = sqrt(n);
    if(n < 2){
        return false;
    }
    else if(n == 2){
        return true;
    }
    else if(n % 2 == 0){
        return false;
    }
    else{
        for (long long i = 3; i < sqr; i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main() {
    long long size;
    cin >> size;
    long long M = 1;
    long long a, b, c;
    long long m;
    long long remainder;
    long long tmp;
    long long modless = 0;
    vector<long long> tmparr(2);
    vector<long long> Ms;
    long long counter = 0;
    bool anyNotPrime = false;

    vector<vector<long long>> arr(size, vector<long long>(2));
    vector<vector<long long>> additional(size, vector<long long>(2));

    for (long long i = 0; i < size; i++)
    {
        cin >> m >> tmp;

        if (isIn(m, Ms) == 0)
        {
            if (isPrime(m) == 1)
            {
                M *= m;
            }
            else{
                if (m % 2 == 0)
                {
                    M *= 2;
                    Ms.push_back(2);
                }
                
                for (long long i = 3; i < m / 2; i += 2)
                {
                    if (isPrime(i) == 1)
                    {
                        if (m % i == 0)
                        {
                            M *= i;
                            Ms.push_back(i);
                        }
                    }
                }
            }
        }
        Ms.clear();

        remainder = m - tmp;

        arr[i][0] = remainder;
        arr[i][1] = m;
    }

    for (vector<long long> subarr : arr)
    {
        a = subarr[0];
        m = subarr[1];

        if (isIn(m, Ms) == 0)
        {
            if(isPrime(m) == 1){
                c = M / m;

                for (long long i = 1; i < m; i++)
                {
                    if ((c * i) % m == 1)
                    {
                        b = i;
                        break;
                    }
                }
                modless += (a*b*c);
                Ms.push_back(m);
            }
            else{
                anyNotPrime = true;
                if (m % 2 == 0)
                {
                    tmparr[0] = a % 2;
                    tmparr[1] = 2;
                    additional[counter] = tmparr;
                    counter++;
                }

                for (long long i = 3; i <= m / 2; i += 2)
                {
                    if (isPrime(i) == 1)
                    {
                        if (m % i == 0)
                        {
                            tmparr[0] = a % i;
                            tmparr[1] = i;
                            additional[counter] = tmparr;
                            counter++;
                        }
                    }
                }
            }
        }
    }

    if (anyNotPrime == 1)
    {
        for (long long i = 0; i < counter; i++)
        {
            a = additional[i][0];
            m = additional[i][1];

            if (isIn(m, Ms) == 0)
            {
                c = M / m;

                for (long long i = 1; i < m; i++)
                {
                    if ((c * i) % m == 1)
                    {
                        b = i;
                        break;
                    }
                }
                modless += (a*b*c);
                Ms.push_back(m);
            }
        }
    }
    
    cout << modless % M << endl;

    return 0;
}