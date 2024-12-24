class Solution {
public:
    void f(TreeNode* root,vector<vector<int>>&v,int i){
        if(root==nullptr) return;
        if (v.size() <= i){
            v.push_back(vector<int>());
        }
        v[i].push_back(root->val);
        f(root->left,v,i+1);
        f(root->right,v,i+1);
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        int i=0;
        f(root,v,i);
        for(int j=0;j<v.size();j++){
            if(j%2==1){
                reverse(v[j].begin(),v[j].end());
            }
        }
        return v;
    }
};
