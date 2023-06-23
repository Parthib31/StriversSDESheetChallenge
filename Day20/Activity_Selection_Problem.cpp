class Solution
{
    static bool comparator(pair<int, int> p1, pair<int, int> p2)
    {
        return (p1.second < p2.second);
    }
    
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> activity;
        
        for(int i = 0 ; i < n ; i++)
        {
            activity.push_back({start[i], end[i]});
        }
        
        sort(activity.begin(), activity.end(), comparator);
        
        int ans = 1;
        int currEnd = activity[0].second;
        
        for(int i = 1 ; i < n ; i++)
        {
            if(activity[i].first > currEnd) 
            {
                ans++;
                currEnd = activity[i].second;
            }
        }
        return ans;
    }
};