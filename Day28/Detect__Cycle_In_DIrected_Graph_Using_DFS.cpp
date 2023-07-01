
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool checkdfs(int node, vector<int>& vis , vector<int>& dfsvis,vector<int> adj[])
  {
      vis[node]=1;
      dfsvis[node]=1; 
      
      for(auto i : adj[node]){
          if(!vis[i]){
              bool cyclefound=checkdfs(i,vis,dfsvis,adj);
              if(cyclefound){
                  
                  return true; 
              }
          }
          else if (dfsvis[i]){
              return true; 
          }
      }
      dfsvis[node]=0;
      return false; 
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
         vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                bool cyclefound= checkdfs(i,vis,dfsvis,adj);
                if(cyclefound){
                    return true;
                }
                
            }
        }
        return false;

    }
};