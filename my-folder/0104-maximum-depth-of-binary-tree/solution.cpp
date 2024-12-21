class Solution {
public:
    int f(TreeNode* root,int depth){
        if (root==nullptr) return depth-1;
        int l=f(root->left,depth+1);
        int r=f(root->right,depth+1);
        int maxi=max(l,r);
        return maxi;
    }
    int maxDepth(TreeNode* root) {
        return f(root,1);
    }
};
