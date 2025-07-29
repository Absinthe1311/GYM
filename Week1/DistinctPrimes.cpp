#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T = 0;
    cin>>T;
    for(int j = 0; j<T; j++)
    {
        int n = 3;
        int count = 0;
        int result = 0;
        int dst = 0;
        cin>>dst;
        vector<int> primes;
        primes.push_back(2);
        while(count < dst)
        {
            int temp_count = 0;
            for(int i = 0; i<primes.size(); i++)
            {
                if(n%primes[i] == 0)
                {
                    temp_count++;
                    if(temp_count == 3)
                    {
                        count++;
                        result = n;
                        break;
                    }
                }
            }
            if(temp_count == 0)
            {
                primes.push_back(n);
            }
            n++;
        }
        cout<<result<<endl;
    }
    return 0;
}