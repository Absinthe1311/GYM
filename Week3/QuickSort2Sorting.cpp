#include <bits/stdc++.h>
using namespace std;

void arrayPrint(vector<int> &arr, int low, int high)
{
    for(int i = low; i <= high; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<<endl;
}

// The order of the array must be maintained
int my_partition(vector<int>&arr, int low, int high)
{
    if(low == high)
        return low;
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j)
    {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// 为了解决这道题目，要保持这个顺序不变，想到的办法是遍历数组分类
int partition(vector<int>&arr, int low, int high)
{
    vector<int> res;
    int index = 0;
    int pivot = arr[low];
    for(int i = low; i <= high; i++)
    {
        if(arr[i] < pivot)
        {
            res.push_back(arr[i]);
            index++;
        }    
    }
    for(int i = low; i <= high; i++)
    {
        if(arr[i] == pivot)
            res.push_back(arr[i]);
    }
    for(int i = low; i <= high; i++)
    {
        if(arr[i] > pivot)
            res.push_back(arr[i]);
    }
    for(int i = low, j = 0; i <= high; i++, j++)
    {
        arr[i] = res[j];
    }
    return low + index;
}

void quickSort(vector <int> &arr, int low, int high) {
	// Complete this function
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        arrayPrint(arr, low, high);
    }
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    return 0;
}