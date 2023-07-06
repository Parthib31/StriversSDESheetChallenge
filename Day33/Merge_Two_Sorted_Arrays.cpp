class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_p=m-1;
        int nums2_p=n-1;
        int merged_p=n+m-1;

        while(nums1_p>=0&&nums2_p>=0){
            if(nums1[nums1_p]>=nums2[nums2_p]){
                nums1[merged_p--]=nums1[nums1_p--];
                // merged_p--;
                // nums1_p--;
            }
            else{
                nums1[merged_p--]=nums2[nums2_p--];
                // merged_p--;
                // nums2_p--;
            }
        }
        while(nums2_p>=0){
            nums1[merged_p--]=nums2[nums2_p--];
        }
    }
};