#include <bits/stdc++.h>
unordered_map<int , int> m;
    TreeNode<int>* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if(inStart > inEnd) return NULL;

        TreeNode<int>* root = new TreeNode<int>(postorder[postEnd]);
        int inorderIndex = m[postorder[postEnd]];
        int noOfNode = inorderIndex - inStart;

        root->left = buildTreeHelper(inorder, postorder, inStart, inorderIndex-1, postStart, 
        postStart+noOfNode-1);
        root->right = buildTreeHelper(inorder, postorder, inorderIndex+1, inEnd, postStart+noOfNode, postEnd-1);
        return root;
    }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
     int size = inorder.size();
        int inStart, inEnd, postStart, postEnd;
        inStart = postStart = 0;
        inEnd = postEnd = size-1;

        for(int i = 0 ; i < size ; i++)
            m[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, inStart, inEnd, postStart, postEnd);
}