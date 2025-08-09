#include<bits/stdc++.h>
using namespace std;

#define MAXN 520

// 现在的标准版本加法
void bigIntSum(string A, string B)
{
    int a[MAXN] = {0};
    int b[MAXN] = {0};
    int c[MAXN] = {0};
    int len = max(A.length(), B.length());
    for(int i = A.length() - 1, j = 0; i >= 0; i--, j++)
        a[j] = A[i] - '0';
    for(int i = B.length() -1, j = 0; i >= 0; i--, j++)
        b[j] = B[i] - '0';
    for(int i = 0; i < len; i++)
    {
        c[i] += a[i] + b[i];
        if(c[i] >= 10)
        {
            c[i+1] += c[i] / 10;
            c[i] %= 10; 
        }
    }
    if(c[len] > 0)
        len++;
    for(int i = len -1; i >= 0; i--)
        cout<<c[i];
    cout<<endl;
}

// 现在的标准版本的减法 默认A >= B
void bigIntSub(string A, string B)
{
    int a[MAXN] = {0};
    int b[MAXN] = {0};
    int c[MAXN] = {0};
    int len = max(A.length(), B.length());
    for(int i = A.length() -1, j = 0; i >= 0; i--, j++)
        a[j] = A[i] - '0';
    for(int i = B.length() -1, j = 0; i >= 0; i--, j++)
        b[j] = B[i] - '0';
    
    for(int i = 0; i < len; i++)
    {
        if(a[i] < b[i])
        {
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];
    }
    // 去除前导0
    while(len > 1 && c[len - 1] == 0)
        len --;
    for(int i = len -1; i >= 0; i--)
        cout<<c[i];
    cout<<endl;
}

// 标准版本的乘法
void bigIntMul(string A, string B)
{
    int a[MAXN] = {0};
    int b[MAXN] = {0};
    int c[MAXN * 2] = {0};
    int lenA = A.length();
    int lenB = B.length();
    int lenC = lenA + lenB; // 最多的位数
    for(int i = A.length() -1, j = 0; i >= 0; i--, j++)
        a[j] = A[i] - '0';
    for(int i = B.length() -1, j = 0; i >= 0; i--, j++)
        b[j] = B[i] - '0';
    for(int i = 0; i < lenA; i++)
      for(int j = 0; j < lenB; j++)
        c[i + j] += a[i] * b[j];
    
    for(int i = 0; i < lenC; i++) //处理进位
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    while(lenC > 1 && c[lenC -1] == 0)
        lenC--;
    
    for(int i = lenC - 1; i >= 0; i--)
        cout<<c[i];
    cout<<endl;
}


int main()
{
    string num1;
    string num2;
    cin>>num1>>num2;
    bigIntSum(num1, num2);
    bigIntSub(num1, num2);
    bigIntMul(num1, num2);
    return 0;
}

