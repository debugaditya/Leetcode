class Solution {
public:
    void f(TreeNode* root,vector<int>&v,int index){
        if(root==nullptr) return;
        if(v.size()==index) v.push_back(root->val);
        f(root->right,v,index+1);
        f(root->left,v,index+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        int index=0;
        f(root,v,index);
        return v;
    }
};
