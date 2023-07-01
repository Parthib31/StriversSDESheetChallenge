#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int V, vector<int> adj[], int start, vector<int>& visited, stack<int>& s)
    {
        visited[start] = 1;

        for(auto node: adj[start])
        {
            if(!visited[node])
                dfs(V, adj, node, visited, s);
        }
        s.push(start);
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
         vector<int> indegrees(V, 0);
        
        for(int i = 0 ; i < V ; i++)
        {
            for(auto node: adj[i])
                indegrees[node]++;
        }

        queue<int> q;
        for(int i = 0 ; i < V ; i++)
        {
            if(indegrees[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();
            ans.push_back(currNode);

            for(auto adjNode : adj[currNode])
            {
                if(--indegrees[adjNode] == 0) q.push(adjNode);
            }
        }
        if(ans.size() == V) return false;
        else return true;
    }
};