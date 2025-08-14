#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&arr, int l, int mid, int r)
{  
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)
        left[i] = arr[l+i];
    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(left[i] > right[j])
            arr[k++] = right[j++];
        else
            arr[k++] = left[i++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
}

void MergeSort(vector<int>&arr,int l, int r)
{
    if(l >= r)  return;
    int mid = l + (r-l)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    Merge(arr, l, mid, r);
}

int main()
{
    vector<int> arr;
    int temp;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while(iss >> temp)
        arr.push_back(temp);
    //cout<<"Out"<<endl;
    MergeSort(arr, 0, arr.size()-1);
    for(int i = 0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}