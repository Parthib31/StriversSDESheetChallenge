class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;

        long long int p_n=abs(n);

        while(p_n>0)
        {
            if(p_n%2==0)
            {
                x*=x;
                p_n/=2;
            }
            else
            {
                ans*=x;
                p_n--;
            }
        }

        if(n<0)
        {
            return (double)1.0/(double)ans;
        }
        return (double)ans;
    }
};