class Solution {
public:
    TreeNode* dfs(TreeNode* root,unordered_map<int,int>&left,unordered_map<int,int>&right){
        int node=root->val;
        if(left.count(node)){
            root->left=new TreeNode(left[node]);
            dfs(root->left,left,right);
        }
        if(right.count(node)){
            root->right=new TreeNode(right[node]);
            dfs(root->right,left,right);
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,int>mp,left,right; int r;
        for(auto it:d){
            if(!mp.count(it[0])) mp[it[0]]=0;
            mp[it[1]]++;
            if(it[2]) left[it[0]]=it[1];
            else right[it[0]]=it[1];
        }
        for(auto it:mp) if(it.second==0) {r=it.first; break;}
        TreeNode* root=new TreeNode(r); 
        return dfs(root,left,right);
    }
};
