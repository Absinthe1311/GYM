#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void sieve(long n, bool * composite, vector<int>&primes)
{
    for(long i = 2; i <= n; i++)
    {
        if(composite[i])
        {
            primes.push_back(i);
            int temp = 2;
            while(temp * i <= n)
            {
                composite[temp * i] = false;
                temp++;
            }
        }
    }
}

void printVector(const vector<int>&v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
}

int main()
{
    long n;
    cin>>n;

    bool composite[n+1];
    memset(composite,true,sizeof(composite));

    composite[0] = composite[1] = false; // 0 and 1 are not prime numbers
    vector<int> primes; // the result vector to store prime numbers

    sieve(n, composite, primes);
    printVector(primes);
    return 0;
}