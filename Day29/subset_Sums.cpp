class Solution
{
    void handmade(vector<int>& a,vector<int>& ans,int i,int sum)
    {
        if(i==a.size())
        {
            ans.push_back(sum);
            return; 
        }
        
        handmade(a,ans,i+1,sum+a[i]);
        handmade(a,ans,i+1,sum);
        
        return;
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        handmade(arr,ans,0,0);
        return ans;
    }
};