class Solution {
public:
    void f(TreeNode* root,int col,int row,map<int,vector<pair<int,int>>>&mp){
        if(!root) return;
        mp[col].push_back({row,root->val});
        f(root->left,col-1,row+1,mp);
        f(root->right,col+1,row+1,mp);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        vector<vector<int>>ans;
        f(root,0,0,mp);
        for(auto it:mp){
            sort(it.second.begin(),it.second.end()); vector<int>v; 
            for(auto it1:it.second) v.push_back(it1.second);
            ans.push_back(v);
        }
        return ans;
    }
};
