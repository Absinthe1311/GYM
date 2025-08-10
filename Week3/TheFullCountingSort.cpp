#include<bits/stdc++.h>
using namespace std;

vector<string> countSort(vector<int>InputArr, vector<string>StringArr)
{
    vector<int> CountArr(100, 0);
    int n = InputArr.size();
    for(int i = 0; i < n; i++)
        CountArr[InputArr[i]] ++;
    for(int i = 0; i < 100 - 1; i++)
        CountArr[i+1] += CountArr[i];
    vector<string> res(n);

    vector<int> test(n);

    for(int i = n-1; i >= 0; i--)
    {
        res[CountArr[InputArr[i]] - 1] = StringArr[i];

        test[CountArr[InputArr[i]] - 1] = InputArr[i];

        CountArr[InputArr[i]]--;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int half = n / 2;
    vector<int> InputArr;
    vector<string> StringArr;
    for(int i = 0; i < n; i++)
    {
        int temp;
        string stemp;
        cin>>temp;
        cin>>stemp;
        InputArr.push_back(temp);
        if(i < half)
            StringArr.push_back("-");
        else
            StringArr.push_back(stemp);
    }
    vector<string>res = countSort(InputArr, StringArr);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}