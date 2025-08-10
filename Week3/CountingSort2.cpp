#include<bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr) {
    int n = arr.size();
    vector<int> count(100, 0);
    for(int i = 0; i < n ; i++)
        count[arr[i]]++;
    for(int i = 0; i < 100-1; i++)
        count[i+1] += count[i];
    vector<int> result(n);
    for(int i = 0; i < n; i++)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> res = countingSort(arr);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout<<endl;
    return 0;
}