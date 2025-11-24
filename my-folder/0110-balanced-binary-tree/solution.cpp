class Solution {
public:
    bool ans=true;
    int height(TreeNode* root){
        if(!root||!ans) return 0;
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1) ans=false;
        return 1+max(right,left);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};
