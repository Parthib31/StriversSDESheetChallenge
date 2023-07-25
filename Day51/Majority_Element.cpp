#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n) {
	// Write your code here.
		int el;
        int count=0;
        for(int i=0;i<n;i++){
        if(count==0)
        {
            el=nums[i];
            count=1;
        }

        else if(el==nums[i])
            count++;

        else
            count--;
        
        }

		count = 0;
        for(int i = 0 ; i < n ; i++)
		{
			if(nums[i] == el)
				count++;
		}
		if(count > n/2) return el;
		else return -1;
    
}