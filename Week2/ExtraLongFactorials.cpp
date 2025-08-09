#include<bits/stdc++.h>
using namespace std;

#define maxn 1000

struct BigInt
{
    int len;
    int a[maxn];
    BigInt(string num)
    { 
        memset(a, 0, sizeof(a)); // 这个比较重要
        len = num.length();
        for(int i = 0; i < len; i++)
            a[i] = num[len - i - 1] - '0';
    }
    void print()
    {
        for(int i = len - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
    }
};

BigInt operator *(BigInt A, int b)
{
    for(int i = 0; i < A.len; i++)
        A.a[i] *= b;
    A.len = A.len + to_string(b).length(); // Adjust length
    for(int i = 0; i < A.len; i++) // flatten
    {
        A.a[i+1] += A.a[i] / 10;
        A.a[i] %= 10;
    }
    while(A.len > 1 && A.a[A.len - 1] == 0)
        A.len--;
    return A;
}

int main()
{
    int n;
    cin >> n;
    BigInt result("1");
    for(int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    result.print();
    return 0;
}