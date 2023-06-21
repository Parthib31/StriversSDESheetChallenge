class Solution {
    bool cyclePresent(int v, vector<int> adj[], vector<int> vis, int start)
    {
        queue<pair<int,int>> q;
        vis[start] = 1;
        q.push({start, -1});
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto val : adj[curr])
            {
                if(vis[val] == 0)
                {
                    q.push({val, curr});
                    vis[val] = 1;
                }
                else if(val != parent) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        
        for(int i = 0 ; i < V ; i++)
        {
            if(!vis[i]) 
            {
                if(cyclePresent(V, adj, vis, i)) 
                    return true;
            }
        }
        return false;
    }
};