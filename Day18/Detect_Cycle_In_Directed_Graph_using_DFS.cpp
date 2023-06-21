class Solution {
private:
    bool cyclePresent(vector<int> adj[], vector<int>& vis, vector<int> path, int curr)
    {
        vis[curr] = 1;
        path[curr] = 1;

        for(auto i : adj[curr])
        {
            if(!vis[i])
            {
                if(cyclePresent(adj, vis, path, i)) return true;
            }
            else if(path[i]) return true;
        }
        path[curr] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto course : prerequisites)
            adj[course[1]].push_back(course[0]);       

        vector<int> vis(numCourses, 0); 
        vector<int> path(numCourses, 0);
        for(int i = 0; i < numCourses ; i++)
        {
            if(!vis[i]) 
            {
                if(cyclePresent(adj, vis, path, i)) return false;
            }
        }  
        return true;
    }
};