#include<bits/stdc++.h>
using namespace std;

#define MAXN 100000

int arr[MAXN];

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else 
        return gcd(b % a, a);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
          cin>>arr[i];
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = gcd(res, arr[i]);
        }
        if(res == 1)
            cout << "YES" << endl;
        else
            cout<< "NO" << endl;
    }
    return 0;
}