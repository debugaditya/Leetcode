class Solution {
public:
    void f(TreeNode* root,vector<int>&v){
        if(!root) return;
        f(root->left,v);
        v.push_back(root->val);
        f(root->right,v);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;     
        f(root,v);
        return v;   
    }
};
