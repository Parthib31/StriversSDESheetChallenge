vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    queue<pair<TreeNode<int> * , int>> q;
    map<int, int> m;
    vector<int> ans;

    if(root)     
      q.push({root, 0});    

    while(!q.empty())
    {
        TreeNode<int> * curr = q.front().first;
        int level = q.front().second;
        q.pop();

        if(!m[level])
            m[level] = curr -> val;

        if(curr -> left) q.push({curr -> left , level-1});
        if(curr -> right) q.push({curr -> right , level+1});
    }

    for(auto i = m.begin() ; i != m.end() ; i++)
        ans.push_back(i -> second);

    return ans;
}