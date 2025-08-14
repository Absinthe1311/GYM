#include<bits/stdc++.h>
using namespace std;

void QuickSort(vector<pair<int,int>>& arr, int l, int r)
{
    if(l > r) return;
    int i = l, j = r;
    int pivot = arr[l+(r-l)/2].first;
    while(i<=j)
    {
        while(arr[i].first < pivot) i++;
        while(arr[j].first > pivot) j--;
        if(i <= j)
            swap(arr[i++], arr[j--]);
    }
    if(l < j) QuickSort(arr, l, j);
    if(i < r) QuickSort(arr, i, r);
}

bool BinarySearch(vector<pair<int,int>>Cost, int l, int r, int i, int target)
{
    if(l > r) return false; // 二分查找要注意的地方
    int mid = l + (r-l)/2;
    if(Cost[mid].first == target && i != mid)
    {
        cout<<min(Cost[i].second,Cost[mid].second)<<" "<<max(Cost[mid].second,Cost[i].second)<<endl;
        return true;
    }    
    else if(Cost[mid].first < target)
        return BinarySearch(Cost, mid+1, r, i, target);
    else
        return BinarySearch(Cost, l, mid-1, i, target);
    return true;
}

void PrintArr(vector<pair<int, int>> arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i].first<<" ";
    cout<<endl;
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i].second<<" ";
    cout<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        vector<pair<int,int>> Cost;
        int k;
        cin>>k;
        int temp;
        int n;
        cin>>n;
        for(int i = 1; i <= n; i++)
        {
            cin>>temp;
            Cost.push_back(make_pair(temp, i));
        }
        QuickSort(Cost, 0, Cost.size()-1);
        //PrintArr(Cost);
        for(int i = 0; i < Cost.size(); i++)
        {
            if(BinarySearch(Cost, 0, Cost.size()-1, i, k-Cost[i].first))
                break;
        }
    }
    return 0;
}