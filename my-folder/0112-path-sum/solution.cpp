class Solution {
public:
    bool f (TreeNode* root, int targetSum,int sum){
        if(!root) return false;
        sum+=root->val;
        if(sum==targetSum&&!root->left&&!root->right) return true;
        return f(root->left,targetSum,sum)||f(root->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root,targetSum,0);
    }
};
