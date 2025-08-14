#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>&arr, int l, int h, int target)
    {
        if(l > h)  return l;
        int mid = l + (h-l)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) return binarySearch(arr, l, mid-1, target);
        else return binarySearch(arr, mid+1, h, target);
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 7, 3, 10, 11};
    cout<<sol.searchInsert(arr, 2)<<endl;
    return 0;
}