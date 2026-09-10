/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    pair<int,int>f(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int>a=f(root->left);
        pair<int,int>b=f(root->right);
        int sum=root->val+a.first+b.first;
        int nodes=1+a.second+b.second;
        if(sum/nodes==root->val) ans++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};
