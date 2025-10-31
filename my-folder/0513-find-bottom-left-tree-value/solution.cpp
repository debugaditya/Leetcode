class Solution {
public:
    int ans,maxi=-1;
    void f(TreeNode* root,int level){
        if(root->left) f(root->left,level+1);
        if(root->right) f(root->right,level+1);
        if(level>maxi) ans=root->val;
        maxi=max(level,maxi);
    }
    int findBottomLeftValue(TreeNode* root) {
        f(root,0);
        return ans;
    }
};
