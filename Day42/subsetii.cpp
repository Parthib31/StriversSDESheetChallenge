class Solution {

    void func(vector<int> nums,vector<vector<int>>& ans,vector<int> ele,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(ele);
            return;
        }      

        ele.push_back(nums[i]);
        func(nums,ans,ele,i+1);
        ele.pop_back();  

        while(i!=nums.size()-1&&nums[i]==nums[i+1])
            i++;
        func(nums,ans,ele,i+1);

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> ele;
        sort(nums.begin(),nums.end());
        func(nums,ans,ele,0);
        return ans;
    }
};