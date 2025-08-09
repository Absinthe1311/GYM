#include<bits/stdc++.h>
using namespace std;

// better solution 
// binary search + lcm
class BetterSolution {
public:
    long long gcd(long long a, long long b)
    {
        if(a == 0) return b;
        else return gcd(b%a, a);
    }
    long long lcm(long long a, long long b)
    {
        return a*b/gcd(a,b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long s = 1;
        long long e = 1e18;
        long long mod = 1e9+7;
        long long lcm_value = lcm(a,b);
        while(s<e)
        {
            long long mid = s + (e-s)/2;
            long long count = mid/a + mid/b - mid/lcm_value;
            if(count < n)
                s = mid + 1;
            else 
                e = mid;
        }
        return s%mod;
    }
};

// My Solution using 4ms
class MySolution {
public:
    int gcd(int a, int b)
    {
        if(a == 0) return b;
        else return gcd(b % a, a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long lcm = a*b/gcd(a,b);
        vector<long long> arr;
        arr.push_back(0);
        long long temp1 = a;
        long long temp2 = b;
        while(temp1 < lcm)
        {
            arr.push_back(temp1);
            temp1 += a;
        }
        while(temp2 < lcm)
        {
            arr.push_back(temp2);
            temp2 += b;
        }
        sort(arr.begin(),arr.end());
        long long m = arr.size();
        long long c = n / m;
        long long d = n % m;
        return (arr[d] + c * lcm) % 1000000007;
    }
};

int main()
{
    BetterSolution sol;
    int n = 3, a = 6, b = 4;
    int result = sol.nthMagicalNumber(n, a, b);
    cout << "The " << n << "th magical number is: " << result << endl;
    return 0;
}