class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        vector<int>start;
        vector<int>endi;
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            endi.push_back(intervals[i][1]);

        }
        sort(start.begin(),start.end());
        sort(endi.begin(),endi.end());
        vector<vector<int>>ans;
        
        ans.push_back({start[0],endi[0]});
        
        int index=1;
        for(int i=1;i<n;i++)
        {
            if(ans[index-1][1]>=start[i])
            {
                ans[index-1][1]=max(ans[index-1][1],endi[i]);
                continue;
            }
            ans.push_back({start[i],endi[i]});
            index++;
        }
        return ans;

    }
};