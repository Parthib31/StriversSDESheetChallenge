class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long int>> q;
        long long int maxWidth = 0;
        if(root) q.push({root , 0});

        while(!q.empty())
        {
            int qsize = q.size();
            long long int currMin = q.front().second;
            long long int leftmost , rightmost;

            for(int i = 0 ; i < qsize ; i++)
            {
                TreeNode* curr = q.front().first;
                long long  ind = q.front().second - currMin;
                q.pop();

                if(i == 0) leftmost = ind;
                if(i == qsize-1) rightmost = ind;

                if(curr->left) q.push({curr->left , 2*ind + 1});
                if(curr->right) q.push({curr->right , 2*ind + 2});
            }
            maxWidth = max(maxWidth , rightmost-leftmost+1);
        }
        return maxWidth;
    }
};