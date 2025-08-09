#include<bits/stdc++.h>
using namespace std;

int getGCD(int a, int b)
{
    if(a==0)
        return b;
    else 
        return getGCD(b % a, a);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, getGCD(a, b));
    return 0;
}