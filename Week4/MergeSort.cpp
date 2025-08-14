#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void merge(vector<int>&arr, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> left(n1), right(n2);
        for(int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for(int i = 0; i < n2; i++)
            right[i] = arr[mid+1+i];
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
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 1, 3, 9, 7};
    sol.mergeSort(arr, 0, arr.size()-1);
    for(int i = 0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}