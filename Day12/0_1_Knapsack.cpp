#include <bits/stdc++.h>

int maxProfitHelper(vector<int> &values, vector<int> &weights, int n, int w , int ind, vector<vector<int>> dp)
{
	if(ind == n) return 0;

	if(dp[ind][w] != -1) return dp[ind][w];

	int pickProfit = 0;
	if(w-weights[ind] >= 0)
		pickProfit = values[ind] + maxProfitHelper(values, weights, n, w-weights[ind], ind+1, dp);
	int notPickProfit = maxProfitHelper(values, weights, n, w, ind+1, dp);

	return dp[ind][w] = max(pickProfit, notPickProfit);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<int> final(w+1, 0) , curr(w+1, 0);
	
	for(int ind = n-1 ; ind >= 0 ; ind--)
	{
		for(int weight = 0 ; weight <= w ; weight++)
		{
			int pickProfit = 0;
			if(weight-weights[ind] >= 0)
				pickProfit = values[ind] + final[weight-weights[ind]];
			int notPickProfit = final[weight];
			curr[weight] = max(pickProfit, notPickProfit);
		}
		final = curr;
	}
	return final[w];
}