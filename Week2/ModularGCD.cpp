#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;

// 我的这个总是会有溢出问题
// ll MOD(ll x, ll n, ll m)
// {
//     if(n == 0)
//         return 1;
//     else if(n % 2 == 0)
//     {
//         ll y = MOD(x, n/2, m);
//         return y * y % m; // 这个地方
//     }
//     else
//     {
//         return (x%m * MOD(x, n-1, m)) % m;
//     }
// }

// 标准实用的快速幂
ll MOD(ll a, ll b, ll m) {
    ll result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            result = (__int128)result * a % m; // 这个地方省略了b--，后面b/=2会达到相同效果
        a = (__int128)a * a % m;
        b /= 2;
    }
    return result;
}

ll gcd(ll a, ll b)
{
    if(a == 0) return b;
    else return gcd(b%a, a);
}

int main() {
	// your code goes here
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll A, B, N;
        scanf("%lld %lld %lld",&A,&B,&N);
        if(A == B)
        {
            ll temp = (MOD(A,N,1e9+7)*2)%(mod);
            printf("%lld\n",temp);
            
        }
        else if(abs(A-B) == 1)
        {
            printf("1\n");
        }
        else 
        {
            ll sub = abs(A-B);
            ll C = (MOD(A,N,sub) + MOD(B,N,sub)) % sub;
            printf("%lld\n",gcd(C,sub)%mod);
        }
    }
    return 0;
}

