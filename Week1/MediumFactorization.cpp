#include<bits/stdc++.h>
using namespace std;

vector<int>was(10000007, 0);

void sieve()
{
    was[0] = was[1] = 1;
    for(int i = 2; i * i < was.size(); i++)
    {
        if(!was[i])
        {
            for(int  j = i+i; j < was.size(); j+=i)
            {
                if(!was[j]) was[j] = i;
            }
        }
    }
}

void primeFactors(int n)
{
    printf("%d",1);
    //vc.push_back(1);
    vector<int> vc;
    while(was[n] && n!=1)
    {
        //printf(" x %d",was[n]);
        vc.push_back(was[n]);
        n /= was[n];
    }
    //printf(" x %d\n",n);
    vc.push_back(n);

    for(int i = 0; i < vc.size(); i++)
    {
        printf(" x %d",vc[i]);
    }
    printf("\n");
}

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n) == 1)
    {
        primeFactors(n);
    }
    return 0;
}