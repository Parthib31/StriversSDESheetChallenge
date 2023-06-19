#include <bits/stdc++.h>

void helperfunc(int vertex, vector<int> &ans, vector<int> adj[],
                vector<bool> &isVisited, int ele) {
  queue<int> q;
  q.push(ele);
  isVisited[ele] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    ans.push_back(curr);

    for (int i = 0; i < adj[curr].size(); i++) {
      if (!isVisited[adj[curr][i]]) {
        q.push(adj[curr][i]);
        isVisited[adj[curr][i]] = true;
      }
    }
  }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
  // Write your code here
  vector<int> adj[vertex];
  for (int i = 0; i < edges.size(); i++) {
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }
  // sort(adj, adj + vertex);
  for(int i = 0 ; i < vertex ; i++)
    sort(adj[i].begin(), adj[i].end());
  
  vector<bool> isVisited(vertex, false);
  vector<int> ans;
  for (int i = 0; i < vertex; i++) {
    if (!isVisited[i])
      helperfunc(vertex, ans, adj, isVisited, i);
  }
  return ans;
}