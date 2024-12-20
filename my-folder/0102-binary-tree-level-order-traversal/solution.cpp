class Solution {
public:
    void f(TreeNode* root,vector<vector<int>>&v,int i){
        if(root==nullptr) return;
        if (i >= v.size()) {
            v.push_back(vector<int>()); 
        }
        v[i].push_back(root->val);
        f(root->left,v,i+1);
        f(root->right,v,i+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        f(root,v, 0);
        return v;

    }
};
