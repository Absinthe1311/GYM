#include<bits/stdc++.h>
using namespace std;

#define maxn 1000

struct bigInt
{
    int len, a[maxn]; // 记录长度，大数的每一位
    bigInt(string num) // 构造函数，将字符串转换为大数
    {
        memset(a, 0, maxn);
        len = num.size();
        for(int i = 0; i<len; i++)
            a[i] = num[len - i - 1] - '0';
    }
    void print() // 打印大数
    {
        for(int i = len -1; i >= 0; i--)
            cout << a[i];
        cout<<endl;
    }
};

bigInt operator-(bigInt a, bigInt b) //大数减法
{
    bigInt res("0");
    res.len = a.len; // 结果的长度为a的长度
    for(int i = 0; i < res.len; i++)
    {
        if(a.a[i] < b.a[i])
        {
            a.a[i] += 10;
            a.a[i+1]--;
        }
        res.a[i] = a.a[i] - b.a[i];
    }
    // 去除前导0
    while(res.len > 1 && res.a[res.len -1] == 0)
    {
        res.len --;
    }
    return res; // 返回结果
}

bool operator>=(bigInt a, bigInt b)
{
    if(a.len != b.len) return a.len > b.len;
    for(int i = a.len -1; i >= 0; i--)
    {
        if(a.a[i] != b.a[i])
            return a.a[i] > b.a[i]; // 比较每一位
    }
    return true; //所有位相等，返回true
}

bool operator==(bigInt a, bigInt b)
{
    if(a.len != b.len) return false;
    for(int i = 0; i < a.len; i++)
        if(a.a[i] != b.a[i]) return false; // 比较每一位
    return true;
}

bigInt operator%(bigInt a, bigInt b)
{
    bigInt res = a;
    while(res >= b) // 当res大于等于b时，进行减法
    {
        res = res - b;
    }
    return res; //返回余数
}

bigInt GCD(bigInt a, bigInt b) // 求大数的GCD
{
    if(a == bigInt("0")) return b;
    else return GCD(b % a, a);
}

int main()
{
    string A, B;
    cin >> A >> B;
    bigInt a(A), b(B); // 得到两个大数a,b
    GCD(a, b).print(); //输出结果
    return 0;
}