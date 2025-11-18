class Solution {
public:
    int ans=0,num=0;
    void f(TreeNode* root){
        num*=10; num+=root->val;
        if(!root->left&&!root->right){ans+=num; num/=10; return;}
        if(root->left) f(root->left); if(root->right) f(root->right);
        num/=10;
    }
    int sumNumbers(TreeNode* root) {
        f(root);
        return ans;
    }
};
