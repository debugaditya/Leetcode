class Solution {
public:
    TreeNode* s;
    unordered_map<TreeNode*,bool>vis;
    int dfs(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>>&mp){
        int ans=0;
        for(auto it:mp[root]){
            if(!vis[it]){
                vis[it]=true;
                ans=max(1+dfs(it,mp),ans);
                vis[it]=false;
            }
        }
        return ans;
    }
    void f(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>>&mp,int start){
        if(!root) return;
        if(root->val==start) s=root;
        if(root->left){
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
        }
        if(root->right){
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
        }
        f(root->left,mp,start);
        f(root->right,mp,start);
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root->left&&!root->right) return 0;
        unordered_map<TreeNode*,vector<TreeNode*>>mp;
        f(root,mp,start);
        vis[s]=true;
        return dfs(s,mp);
    }
};
