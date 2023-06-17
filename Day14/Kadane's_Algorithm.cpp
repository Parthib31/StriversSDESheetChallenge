#include <bits/stdc++.h> 
long long maxSubarraySum(int a[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long int t_sum=0;
        long long int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>t_sum)
                t_sum=sum;
            if(sum<0)          
                sum=0;          
            
        }
    return t_sum;    
}