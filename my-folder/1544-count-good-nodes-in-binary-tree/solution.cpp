class Solution {
public:
    void f(TreeNode* root,int maxi,int &ans){
        if(!root) return;
        if(root->val>=maxi) {ans++; maxi=root->val;}
        f(root->left,maxi,ans); f(root->right,maxi,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0; f(root,INT_MIN,ans);
        return ans;   
    }
};
