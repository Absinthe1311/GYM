#include<bits/stdc++.h>
using namespace std;

int nums[1005];

int main()
{
    int n = 0;
    int k = 0;
    cin>>n;
    cin>>k;
    vector<int> primes; // store all prime numbers from 2 to n
    for(int i = 2; i <= n; i++)
    {
        if(!nums[i]) // 0 represent a prime
        {
            primes.push_back(i);
            for(int j = i*i; j <= n; j+=i)
            {
                nums[j] = 1;
            }
        }
    }
    int count = 0;
    for(int i = 0; i<primes.size(); i++)
    {
        int target = primes[i];
        for(int j = 0; j<primes.size()-1;j++)
        {
            if(primes[j] + primes[j+1] + 1 == target)
            {
                count++;
                break;
            }
        }
    }
    if(count >= k)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}