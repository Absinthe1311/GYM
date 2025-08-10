#include<bits/stdc++.h>
using namespace std;

vector<int> coutingSort(vector<int>& arr)
{
    int n = arr.size();
    if(n == 0) return arr;
    int maxv = arr[0];
    for(int i = 0; i < n; i++)
      maxv = max(maxv, arr[i]);
    vector<int> count(maxv+1, 0);
    for(int i = 0; i < n; i++)
      count[arr[i]]++;
    for(int i = 0; i < maxv; i++)
      count[i+1] += count[i];
    vector<int> output(n);
    for(int i = n-1; i >= 0; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    return output;
}

int main()
{
    vector<int> arr = {1,12,5,26,7,14,3,7,2};
    vector<int> sortedArr = coutingSort(arr);
    for(int i = 0; i < sortedArr.size(); i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout<<endl;
    return 0;
}