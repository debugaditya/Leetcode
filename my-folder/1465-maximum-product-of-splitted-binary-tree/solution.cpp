
class Solution {
public:
    unordered_map<TreeNode*,long long>mp;
    int f(TreeNode* root){
        if(!root) return 0;
        int left=f(root->left);
        int right=f(root->right);
        return mp[root]=left+right+root->val;
    }
    long long maxProduct(TreeNode* root) {
        long long ans=0; f(root);
        long long total=mp[root];
        for(auto it:mp){
            ans=max(ans,(total-it.second)*it.second);
        } 
        return ans%1000000007;
    }
};
