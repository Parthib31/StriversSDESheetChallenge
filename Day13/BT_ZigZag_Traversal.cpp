vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
        // Write your code here!
        bool leftToRight = true;
        queue<BinaryTreeNode<int>*> q;
        vector<int> ans;
        if(root) q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> currv;
            while(size-- > 0)
            {
                BinaryTreeNode<int>* currNode = q.front();
                q.pop();               
                currv.push_back(currNode->data);

                if(currNode->left)                     
                    q.push(currNode->left);
                if(currNode->right)                
                    q.push(currNode->right);                                                 
            }

            if(!leftToRight)            
                reverse(currv.begin(), currv.end());
            
            ans.insert(ans.end(), currv.begin(), currv.end());
            leftToRight = !leftToRight;
        }  
        return ans;
}