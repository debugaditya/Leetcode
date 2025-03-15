class Solution {
public:
    
    int f(TreeNode* root,unordered_map<TreeNode*, int>&dp){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        return dp[root]=max(f(root->left,dp) + f(root->right,dp), 
           root->val + (root->left ? f(root->left->left,dp) + f(root->left->right,dp) : 0) 
                     + (root->right ? f(root->right->left,dp) + f(root->right->right,dp) : 0));

    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return f(root,dp);
    }
};
