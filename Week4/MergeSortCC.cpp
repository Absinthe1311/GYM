#include<bits/stdc++.h>
using namespace std;

int maxDepth = 0;
int reached = 0;

void MergeSort(int s, int t, int i,int depth)
{
    if(s >= t)
    {
        if(s == t && s == i)
        {
            cout<<s<<" "<<t<<endl;
            reached = 1;
            depth++;
            if(depth > maxDepth)
                maxDepth = depth;
        }
        return;
    }
    if(s<=i && i <= t) // reached
    {
        reached = 1;
        cout<<s<<" "<<t<<endl;
        depth++;
        if(depth > maxDepth)
            maxDepth = depth;
    }
    int mid = s + (t-s) / 2;
    MergeSort(s, mid, i, depth);
    MergeSort(mid+1, t, i, depth);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int s, t, i;
        cin>>s>>t>>i;
        maxDepth = 0;
        reached = 0; // reach the i index
        MergeSort(s, t, i, 0);
        if(reached)
            cout<<maxDepth<<endl;
        else 
            cout<<"-1"<<endl;
    }
    return 0;
}