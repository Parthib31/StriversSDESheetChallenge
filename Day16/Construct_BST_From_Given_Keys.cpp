class Solution {
    TreeNode* formBST(vector<int>& nums, int s, int e)
    {
        if(s > e) return NULL;
        
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root-> left = formBST(nums, s, mid-1);
        root-> right = formBST(nums, mid+1, e);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return formBST(nums, 0, nums.size()-1);
    }
};