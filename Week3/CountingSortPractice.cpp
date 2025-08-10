#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string countSort(string s) {
        // code here
        int n = s.length();
        vector<int> count(26, 0);
        for(int i = 0; i < n; i++)
          count[s[i]-'a']++;
        for(int i = 0; i < 25; i++)
          count[i+1] += count[i];
        string output(n, ' ');
        for(int i = n-1; i >= 0; i--)
        {
            output[count[s[i]-'a']-1] = s[i];
            count[s[i]-'a']--;
        }
        return output;
    }
};

int main()
{
    Solution sol;
    string s;
    cin >> s;
    cout << sol.countSort(s) << endl;
    return 0;
}