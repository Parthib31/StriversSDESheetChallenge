vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    stack<pair<BinaryTreeNode<int> * , int>> s;
    if(root) s.push({root , 1});

    while(!s.empty())
    {
        BinaryTreeNode<int> * curr = s.top().first;
        int itr = s.top().second;
        s.pop();

        if(itr == 1)
        {
            ans[1].push_back(curr -> data);
            s.push({curr , 2});
            if(curr -> left) s.push({curr -> left, 1});
        }
        else if(itr == 2)
        {
            ans[0].push_back(curr -> data);
            s.push({curr , 3});
            if(curr -> right) s.push({curr -> right, 1});
        }
        else
            ans[2].push_back(curr -> data);
    }
    return ans;
}