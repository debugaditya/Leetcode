class Solution {
public:
    unordered_map<int,int>mp; int freq=0; vector<int>ans;
    void f(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        if(mp[root->val]==freq) ans.push_back(root->val);
        if(mp[root->val]>freq) {ans={root->val}; freq=mp[root->val];}
        f(root->left); f(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        f(root);
        return ans;
    }
};
