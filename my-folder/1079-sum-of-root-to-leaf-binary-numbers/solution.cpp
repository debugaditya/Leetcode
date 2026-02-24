class Solution {
public:
    void f(TreeNode* root,int &ans,int &num){
        if(!root) return;
        num*=2; num+=root->val;
        if(!root->left&&!root->right) ans+=num;
        f(root->left,ans,num); f(root->right,ans,num);
        num/=2;
    }
    int sumRootToLeaf(TreeNode* root) {
        int num=0,ans=0;
        f(root,ans,num);
        return ans;
    }
};
