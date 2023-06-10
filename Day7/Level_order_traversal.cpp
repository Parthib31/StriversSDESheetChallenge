vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    if(root) 
        q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int> *curr = q.front();
        q.pop();
        ans.push_back(curr -> val);
        
        if(curr -> left) q.push(curr -> left);
        if(curr -> right) q.push(curr -> right);
    }
    return ans;
}