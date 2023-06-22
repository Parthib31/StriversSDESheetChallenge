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
    TreeNode* formBST(vector<int>& pre, int bound, int& ind)
    {
        if(ind == pre.size() || pre[ind] > bound) return NULL;

        TreeNode* root = new TreeNode(pre[ind]);
        ind++;

        root->left = formBST(pre, root->val, ind);
        root-> right = formBST(pre, bound, ind);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int bound = INT_MAX;
        int ind = 0;
        return formBST(pre, bound, ind);
    }
};