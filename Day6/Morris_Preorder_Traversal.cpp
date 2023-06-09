vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    TreeNode* curr = root;
    while(curr != NULL)
    {

      if (curr->left == NULL) {
        ans.push_back(curr->data);
        curr = curr->right;
      }

      else {
        TreeNode *leftSubtree = curr->left;
        while (leftSubtree->right != NULL && leftSubtree->right != curr)
          leftSubtree = leftSubtree->right;

        if (leftSubtree->right == NULL) {
          leftSubtree->right = curr;
          ans.push_back(curr -> data);
          curr = curr->left;    
        } else {
          leftSubtree->right = NULL;
          curr = curr->right;
        }
      }
    }
    return ans;
}