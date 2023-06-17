/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* tree1, TreeNode* tree2)
    {
        if(!tree1 && !tree2) return true;
        if(!tree1 || !tree2) return false;

        if(tree1->val != tree2->val) return false;

        return solve(tree1->left, tree2->right) && solve(tree1->right, tree2->left);        
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};