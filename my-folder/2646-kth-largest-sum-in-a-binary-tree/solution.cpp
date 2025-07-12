class Solution {
public:
    void f(TreeNode* root,int level,vector<long long>&mp){
        if(!root) return;
        if(level<mp.size()) mp[level]+=root->val;
        else mp.push_back(root->val);
        f(root->left,level+1,mp);
        f(root->right,level+1,mp);
        return;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>mp;
        f(root,0,mp);
        sort(mp.begin(),mp.end(),greater<long long>());
        return k>mp.size()?-1:mp[k-1];
    }
};
