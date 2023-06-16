int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    sort(arr, arr+n);
    	sort(dep, dep+n);
    	int currPlatform = 0, arrInd = 0, depInd = 0, ans= 0;
    	while(arrInd < n)
    	{
    	    if(arr[arrInd] <= dep[depInd])
    	    {
    	        currPlatform++;
    	        arrInd++;
    	    }
    	    else
    	    {
    	        currPlatform--;
    	        depInd++;
    	    }
    	    ans = max(ans, currPlatform);
    	}
    	return ans;
}