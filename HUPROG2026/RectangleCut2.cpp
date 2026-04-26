#include <iostream>
#include <vector>
using std::vector;

int min_cuts(int a, int b, vector<vector<int> > &mem) {
    int min = mem[a][b];
    if (min > 0)
        return min;

    if (a%b==0)
        min= a/b-1;
    else if (b%a==0)
        min= b/a -1;

    else {
        for (int i=1; i<a/2; i++) {
            int m = min_cuts(i,b, mem);
            int n = min_cuts(a-i, b, mem);
            if (min<0 or m+n+1<min)
                min = m + n + 1;
        }
        for (int j=1; j<b/2; j++) {
            int m = min_cuts(a,j, mem);
            int n = min_cuts(a, b-j, mem);
            if (min<0 or m+n+1<min)
                min = m + n + 1;
        }
    }
    mem[a][b] = min;
    return min;
}

int main() {
    int a, b; 
    std::cin >> a >> b; 

    vector<vector<int> > mem(a+1, vector<int>(b+1, -1));
    int res = min_cuts(a,b,mem);

    std::cout << res << std::endl;

    return 0;
}
