#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    /* partition */
    while(i <= j)
    {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    /* recursion */
    if(left < j) quickSort(arr, left, j);
    if(i < right) quickSort(arr, i, right);
}

int main()
{
    int arr[] = {1,12,5,26,7,14,3,7,2};
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}