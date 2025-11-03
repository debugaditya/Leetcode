class Solution {
public:
    TreeNode* f(int l,int r,vector<int>& nums){
        if(l>r) return nullptr;
        if(l==r) return new TreeNode(nums[l]);
        int maxi=-1,idx=-1;
        for(int i=l;i<=r;i++) if(nums[i]>maxi){idx=i; maxi=nums[i];}
        return new TreeNode(maxi,f(l,idx-1,nums),f(idx+1,r,nums));
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(0,nums.size()-1,nums);
    }
};
