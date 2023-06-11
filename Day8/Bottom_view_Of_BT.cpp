vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    queue<pair<BinaryTreeNode<int> * , int>> q;
    map<int, int> m;
    vector<int> ans;

    if(root)     
      q.push({root, 0});    

    while(!q.empty())
    {
        BinaryTreeNode<int> * curr = q.front().first;
        int level = q.front().second;
        m[level] = curr -> data;
        q.pop();

        if(curr -> left) q.push({curr -> left , level-1});
        if(curr -> right) q.push({curr -> right , level+1});
    }

    for(auto i = m.begin() ; i != m.end() ; i++)
        ans.push_back(i -> second);

    return ans;
}