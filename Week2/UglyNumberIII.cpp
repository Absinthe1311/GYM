#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    ll gcd(ll a, ll b)
    {
        if(a == 0) return b;
        else return gcd(b%a, a);
    }
    ll lcm(ll a, ll b)
    {
        return a*b/gcd(a,b);
    }
    ll count(ll num, ll a, ll b, ll c)
    {
        return num/a + num/b + num/c - num/lcm(a, b) - num/lcm(b,c) - num/lcm(a,c) + num/lcm(a,lcm(b,c));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll s = 0, e = 2e9, result = 0;
        while(s <= e)
        {
            ll mid = s + (e-s)/2;
            if(count(mid, a, b, c) >= n)
            {
                result = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int n = 5, a = 2, b = 3, c = 5;
    int result = sol.nthUglyNumber(n, a, b, c);
    cout << "The " << n << "th ugly number is: " << result << endl;
    return 0;
}