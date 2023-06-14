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
int preIndex;
unordered_map<int, int> m;
class Solution
{
    TreeNode *solve(vector<int> &preorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preIndex++]);
        int inorderIndex = m[root->val];

        root->left = solve(preorder, inStart, inorderIndex - 1);
        root->right = solve(preorder, inorderIndex + 1, inEnd);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preIndex = 0;
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        return solve(preorder, inStart, inEnd);
    }
};