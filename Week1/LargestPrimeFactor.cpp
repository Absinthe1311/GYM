#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int largestPrimeFactor = 2;
    int i = 2;
    while(n>1)
    {
        if(n % i == 0)
        {
            largestPrimeFactor = i;
            n = n / i;
        }
        else 
        {
            i++;
        }
    }
    cout<<largestPrimeFactor<<endl;
    return 0;
}