class Solution {
public:
    void inorder(TreeNode* root,int&cnt,int k,int& ans){
        if(!root) return;
        if(cnt==k) return;
        inorder(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k) ans=root->val;
        inorder(root->right,cnt,k,ans);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
        inorder(root,cnt,k,ans);
        return ans;
    }
};
