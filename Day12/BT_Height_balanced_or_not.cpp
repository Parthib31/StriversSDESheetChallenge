int height(BinaryTreeNode<int>* root, bool& helper) {
        if(!root || !helper) return 0;

        int left = height(root -> left, helper);
        if(!helper) return 0;
        int right = height(root -> right, helper);
        if(!helper) return 0;

        if(abs(left - right) > 1) 
        {
            helper = false;
            return 0;
        }

        return 1 + max(left , right);
    }

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool helper = true;
    height(root, helper);
    return helper;
}