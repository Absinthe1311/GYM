#include<bits/stdc++.h>
using namespace std;

vector<int> quickSortPartition(vector<int> arr, int low, int high)
{
    int pivot = arr[low];
    vector<int> left, right, equal;
    for(int i = low; i < high; i++)
    {
        if(arr[i] < pivot)
            left.push_back(arr[i]);
        else if(arr[i] > pivot)
            right.push_back(arr[i]);
        else
            equal.push_back(arr[i]);
    }
    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    vector<int> sorted = quickSortPartition(arr, 0, n);
    for(int i = 0; i < sorted.size(); i++)
        printf("%d ", sorted[i]);
    printf("\n");
    return 0;
}