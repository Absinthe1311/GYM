#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int l, int h, int target)
{
    if(l > h)   return -1;
    int mid = l + (h-l)/2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return BinarySearch(arr, l, mid-1, target);
    else 
        return BinarySearch(arr, mid+1, h, target);
}

int main()
{
    vector<int> arr = {1, 4, 7, 8, 9};
    cout<<BinarySearch(arr, 0, arr.size()-1, 9)<<endl;
    return 0;
}