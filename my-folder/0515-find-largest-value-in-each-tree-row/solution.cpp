class Solution {
public:
    void f(TreeNode* root,vector<int>&v,int i){
        if(root==nullptr) return;
        if(v.size()<=i) v.push_back(root->val);
        v[i]=max(v[i],root->val);
        f(root->left,v,i+1);
        f(root->right,v,i+1);
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        int i=0;
        vector<int>v;
        f(root,v,i);
        return v;
    }
};
