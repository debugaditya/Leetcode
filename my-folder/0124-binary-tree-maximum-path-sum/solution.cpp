class Solution {
public:
    int f(TreeNode* root,int &ans){
        if(!root) return 0;
        int left=f(root->left,ans);
        int right=f(root->right,ans);
        ans=max({ans,left+root->val,right+root->val,left+right+root->val,root->val});
        return max(max(left,right)+root->val,root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        f(root,ans);
        return ans;
    }
};
