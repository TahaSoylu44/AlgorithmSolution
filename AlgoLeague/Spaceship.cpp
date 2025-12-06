#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

long long add(long long a, long long b) {
    return (a + b + MOD) % MOD; 
}

long long multipy(long long x, long long y)
{
    return ((x % MOD) * (y % MOD)) % MOD; 
}

long long factorial(long long n)
{
    long long result = 1;
    for (long long i = 2; i <= n; i++)
    {
        result = multipy(result, i);
    }
    return result;
}

long long getMedian(vector<int>& arr)
{
    long long size = arr.size();
    long long idx = size / 2;
    return arr[idx];
}

long long getAbs(long long n)
{
    if (n < 0) return -1 * n;
    else return n;
}

long long getDistance(vector<int>& v1, vector<int>& v2)
{
    long long x = v1[0] - v2[0];
    long long y = v1[1] - v2[1];
    long long z = v1[2] - v2[2];
    return getAbs(x) + getAbs(y) + getAbs(z);
}

long long getSumOfAllPairs(vector<int>& coords) {
    long long n = coords.size();
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        long long coeff = i - (n - 1 - i);
        long long term = multipy(coords[i], coeff);
        total = add(total, term);
    }
    return total;
}

long long minimumDistance(vector<vector<int>>& planets)
{
    long long size = planets.size();
    long long total = 0;

    vector<int> Xcoordinate(size);
    vector<int> Ycoordinate(size);
    vector<int> Zcoordinate(size);
    vector<int> startingPoint(3);

    for (int i = 0; i < size; i++)
    {
        Xcoordinate[i] = planets[i][0];
        Ycoordinate[i] = planets[i][1];
        Zcoordinate[i] = planets[i][2];
    }

    sort(Xcoordinate.begin(), Xcoordinate.end());
    sort(Ycoordinate.begin(), Ycoordinate.end());
    sort(Zcoordinate.begin(), Zcoordinate.end());
    
    startingPoint[0] = getMedian(Xcoordinate);
    startingPoint[1] = getMedian(Ycoordinate);
    startingPoint[2] = getMedian(Zcoordinate);

    long long sumStartToPlanets = 0;
    for (int i = 0; i < size; i++)
    {
        long long dist = getDistance(startingPoint, planets[i]);
        sumStartToPlanets = add(sumStartToPlanets, dist); // Modüler toplama
    }

    long long sumPairsX = getSumOfAllPairs(Xcoordinate);
    long long sumPairsY = getSumOfAllPairs(Ycoordinate);
    long long sumPairsZ = getSumOfAllPairs(Zcoordinate);
    
    long long totalPairDistance = add(sumPairsX, add(sumPairsY, sumPairsZ));

    long long NminusOneFactorial = factorial(size - 1);

    long long term1 = multipy(NminusOneFactorial, sumStartToPlanets);
    total = add(total, term1);

    long long term2 = multipy(2, multipy(NminusOneFactorial, totalPairDistance));
    total = add(total, term2);

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int repetition;
    if (cin >> repetition) { 
        for (int i = 0; i < repetition; i++)
        {
            int size;
            cin >> size;

            vector<vector<int>> planets(size, vector<int>(3));

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cin >> planets[i][j];
                }
            }

            std::cout << minimumDistance(planets) << std::endl;
        }
    }

    return 0;
}