class Solution {
public:
    int f(TreeNode* root, int low, int high){
        if(!root) return 0;
        if(root->val>=low&&root->val<=high) return root->val+f(root->left,low,high)+f(root->right,low,high);
        return f(root->left,low,high)+f(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return f(root,low,high);
    }
};
