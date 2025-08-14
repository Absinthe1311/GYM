#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll res;

void Merge(vector<int>&arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left, right;
    for(int i = 0; i<n1; i++)
        left.push_back(arr[l+i]);
    for(int i = 0; i<n2; i++)
        right.push_back(arr[mid+i+1]);
    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2)
    {
        if(left[i] > right[j])
        {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
        else 
            arr[k++] = left[i++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
}

void MergeSort(vector<int>&arr, int l, int r)
{
    if(l >= r)
        return;
    int mid = l + (r-l) / 2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    Merge(arr, l, mid, r);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        res = 0;
        vector<int> input;
        int n;
        cin>>n;
        while(n--)
        {
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        MergeSort(input, 0, input.size()-1);
        cout<<res<<endl;
    }
}