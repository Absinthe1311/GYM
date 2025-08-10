#include<bits/stdc++.h>
using namespace std;

class MySolution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        int pi = partition(arr, low, high);
        if(low < pi-1)
            quickSort(arr, low, pi-1);
        if(pi+1 < high)
            quickSort(arr, pi+1, high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int i = -1;
        int pivot = arr[high];
        for(int j = 0; j<=high-1; j++)
        {
            if(arr[j] < pivot)
                swap(arr[++i], arr[j]);
        }
        swap(arr[++i], arr[high]);
        return i; // this is the position of the pivot
    }
};

// passed solution
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[high];
        int i = low;
        int j = high;
        while(i < j)
        {
            while(arr[i] < pivot) i++; //i一定指向一个>=piovt的值
            while(arr[j] >= pivot) j--; //j一定指向一个<pivot的值
            if(i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i], arr[high]); //将pivot放到正确位置
        return i; //返回pivot的位置
    }
};

int main()
{
    vector<int> arr = {1,4,7,7,8,5,1,6,8};
    Solution sol;
    sol.quickSort(arr, 0, arr.size()-1);
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}