class Solution {
public:
    vector<int>mp=vector<int>(10,0); int cnt=0;
    int f(TreeNode* root){
        if(!root) return 0;
        mp[root->val]++; mp[root->val]&1==1?cnt++:cnt--; int temp=cnt;
        if(!root->left&&!root->right) {mp[root->val]&1==1?cnt--:cnt++; mp[root->val]--; return temp<=1?1:0;}
        int sum=f(root->left)+f(root->right);
        mp[root->val]&1==1?cnt--:cnt++; mp[root->val]--; 
        return sum;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return f(root);
    }
};
