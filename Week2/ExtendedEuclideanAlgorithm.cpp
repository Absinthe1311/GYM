#include<bits/stdc++.h>
using namespace std;

int getExtendedGCD(int a, int b, int &x, int &y)
{
    if(a==0)
    {
        x = 0; 
        y = 1;
        return b;
    }
    else 
    {
        int x1, y1;
        int gcd = getExtendedGCD(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return gcd;
    }
}


int main()
{
    int a, b, x, y;
    scanf("%d %d", &a, &b);
    int gcd = getExtendedGCD(a, b, x, y);
    printf("%d = %d * %d + %d * %d\n", gcd, a, x, b, y);
    return 0;
}