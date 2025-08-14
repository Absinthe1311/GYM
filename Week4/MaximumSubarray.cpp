#include<bits/stdc++.h>
using namespace std;



// the simplest solution 
class Solution
{
    public:
    int maxSubArray(vector<int>&nums)
    {
        int total = 0;
        int res = nums[0];
        for(int i = 0; i<nums.size(); i++)
        {
            if(total < 0)
                total = 0;
            total += nums[i];
            if(total > res)
                res = total;
        }
        return res;
    }
};

int main()
{  
    Solution sol;
    vector<int> arr = {5,4,-1,7,8};
    cout<<sol.maxSubArray(arr)<<endl;
    return 0;
}