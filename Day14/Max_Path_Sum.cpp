int solve( TreeNode<int>* root, long long int& maxSum)
    {
        if(!root) return 0;

        long long int leftSum = solve(root->left, maxSum);
        long long int rightSum = solve(root->right, maxSum);

        maxSum = max(maxSum , leftSum + rightSum + root->val);
        return max(leftSum , rightSum) + root->val;
    }

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
        if(!root || !root-> left || !root->right) return -1;
        long long int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
}