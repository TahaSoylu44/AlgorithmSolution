#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqr = sqrt(n);

    for (int i = 3; i <= sqr; i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

vector<vector<int>> createDivisorArray(int n)
{
    int x = 2;
    int counter = 0;
    int start = n;
    vector<vector<int>> myarray;

    while (n % 2 == 0)
    {
        n /= 2;
        counter++;
    }
    myarray.push_back({2,counter});
    counter = 0;

    for (x = 3; x <= sqrt(start); x += 2)
    {
        if (isPrime(x))
        {
            n = start;
            while (n % x == 0)
            {
                n /= x;
                counter++;
            }
            myarray.push_back({x,counter});
            counter = 0;
        }
    }
    return myarray;
}

int getNumberOfDivisors(vector<vector<int>>& divisorVector)
{
    int count = 1;

    for (int i = 0; i < divisorVector.size(); i++)
    {
        count *= (divisorVector[i][1] + 1);
    } 
    return count;  
}

int triangleNumber(int n)
{
    return n * (n + 1) * 0.5;
}

int getHighestTriangleNumber()
{
    vector<vector<int>> arrayOfTriangle;
    int index = 10;
    int numOfDivisors;
    int triangle_number;

    while (1)
    {
        triangle_number = triangleNumber(index);

        if (!isPrime(triangle_number))
        {
            arrayOfTriangle = createDivisorArray(triangle_number);
            numOfDivisors = getNumberOfDivisors(arrayOfTriangle);

            if (numOfDivisors > 500) return triangle_number;
        }
        index++;
    }
}


int main() {

    std::cout << getHighestTriangleNumber();
    
    return 0;
}