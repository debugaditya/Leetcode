class Solution {
public:
    void f(TreeNode* root, int level,vector<int>&sum){
        if(!root) return;
        if(sum.size()<=level) sum.push_back(root->val);
        else sum[level]+=root->val;
        f(root->left,level+1,sum);
        f(root->right,level+1,sum);
        return;
    }
    void g(TreeNode* root, int level,vector<int>&sum){
        if(!root) return;
        root->val+=sum[level];
        if(root->right&&root->left){
            int s=root->right->val+root->left->val;
            root->left->val=-s; root->right->val=-s;
        }
        else{ if(root->left) root->left->val*=-1; if(root->right) root->right->val*=-1;}
        g(root->left,level+1,sum);
        g(root->right,level+1,sum);
        return;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>sum; 
        f(root,0,sum); root->val*=-1; g(root,0,sum);
        return root;
    }
};
