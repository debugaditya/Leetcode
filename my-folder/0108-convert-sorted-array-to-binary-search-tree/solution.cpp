class Solution {
public:
    TreeNode* f(int i,int j,vector<int>&nums){
        if(i==j) return new TreeNode(nums[i]);
        if(i>j||i<0||j==nums.size()) return nullptr;
        TreeNode* ans=new TreeNode(nums[(j+i)/2]); 
        ans->right=f((j+i)/2+1,j,nums);
        ans->left=f(i,(j+i)/2-1,nums);
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(0,nums.size()-1,nums);
    }
};
