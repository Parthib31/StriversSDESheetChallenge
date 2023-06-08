vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    stack<TreeNode*> s;
    TreeNode* curr = root;

    while(true)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        if(s.empty()) break;
        curr = s.top() -> right;
        if(curr == NULL)
        {
            TreeNode* temp = s.top();
            s.pop();
            ans.push_back(temp -> data);

            while(!s.empty() && s.top() -> right == temp)
            {
                temp = s.top();
                s.pop();
                ans.push_back(temp -> data);
            }
        }
    }
    return ans;
}