#include<bits/stdc++.h>
using namespace std;

void arrayPrint(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int my_partition(vector<int>&arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[high];
    while(i < j)
    {
        while(arr[i] < pivot) i++;
        while(arr[j] >= pivot) j--;
        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int partition(vector<int>&arr, int low, int high)
{
    int i = low;
    int pivot = arr[high];
    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int>&arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        arrayPrint(arr);
        quickSort(arr, low, pi -1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    quickSort(arr, 0, n-1);
    return 0;
}