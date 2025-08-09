#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0) return b;
    else return gcd(b % a, a);
}
// return b % a
int mod(int a, string b)
{
    int res = 0;
    for(int i = 0; i < b.length(); i++)
    {
        res = (res * 10 + (b[i] - '0')) % a;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        string b;
        cin >> a >> b;
        if(a == 0)
        {
            cout << b << endl; // GCD(0, b) = b
            continue;
        }
        int b_mod = mod(a, b);
        cout << gcd(a, b_mod) << endl;
    }
    return 0;
}