#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
		vector<int> ans(n,1);

        for(int row=1; row<m; row++)
        {
            for(int col=1; col<n; col++)
            {
                ans[col]=ans[col]+ans[col-1];
            }
        }
        return ans[n-1];
}