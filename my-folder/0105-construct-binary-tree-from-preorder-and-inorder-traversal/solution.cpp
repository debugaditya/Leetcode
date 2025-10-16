class Solution {
public: 
    TreeNode* f(int i,int j,unordered_map<int,int>&mp,queue<int>& pre){
        if(i>j||pre.empty()) return NULL;
        int val=pre.front(); pre.pop();
        TreeNode* a=new TreeNode(val);
        if(i==j) return a;
        a->left=f(i,mp[val]-1,mp,pre);
        a->right=f(mp[val]+1,j,mp,pre);
        return a;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        queue<int>pre(preorder.begin(),preorder.end());
        unordered_map<int,int>mp; for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return f(0,inorder.size()-1,mp,pre);
    }
};
