#include<bits/stdc++.h>
using namespace std;

int powMod(long long x, long long n, long long m){
    if(n == 0) return 1;
    else if(n % 2 == 0){
        long long y = powMod(x, n / 2, m);
        long long temp = y*y;
        return temp % m;
    }
    else {
        return ((x % m) * powMod(x, n-1, m)) % m;
    }
}

int main()
{
    int x, n, m;
    cin>> x >> n >> m;
    cout << powMod(x, n, m) <<endl;
    return 0;
}
