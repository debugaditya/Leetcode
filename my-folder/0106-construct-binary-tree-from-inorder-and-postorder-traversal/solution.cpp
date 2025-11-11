class Solution {
public:
    TreeNode* f(int i,int j,unordered_map<int,int>&mp,stack<int>& pos){
        if(i>j||pos.empty()) return NULL;
        int val=pos.top(); pos.pop();
        TreeNode* a=new TreeNode(val);
        a->right=f(mp[val]+1,j,mp,pos);
        a->left=f(i,mp[val]-1,mp,pos);
        return a;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp; stack<int>pos(postorder.begin(),postorder.end());
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return f(0,inorder.size()-1,mp,pos);
    }
};
