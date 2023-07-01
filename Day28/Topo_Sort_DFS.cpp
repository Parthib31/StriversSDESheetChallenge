
class Solution
{
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
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> visited(V, 0);
        stack<int> s;

	    for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i])
                dfs(V, adj, i, visited, s);
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;        
	}
};