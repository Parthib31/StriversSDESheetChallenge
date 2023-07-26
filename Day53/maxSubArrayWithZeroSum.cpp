#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > A) {
  // Write your code here
  unordered_map<int, int> m;
  int n = A.size();
        int sum = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            sum += A[i];
            if(sum == 0)
                ans = i+1;
            else if(m.find(sum) != m.end())
                ans = max(ans, i - m[sum]);
            else 
                m[sum] = i;
        }
        return ans;
}