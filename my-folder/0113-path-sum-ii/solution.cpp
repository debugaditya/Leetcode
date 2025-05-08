class Solution {
public:
    void f (TreeNode* root, int targetSum,int sum,vector<int>&temp,vector<vector<int>>&ans){
        if(!root) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(sum==targetSum&&!root->left&&!root->right){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        f(root->left,targetSum,sum,temp,ans);
        f(root->right,targetSum,sum,temp,ans);
        temp.pop_back();
        return; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(root,targetSum,0,temp,ans);
        return ans;
    }
};
