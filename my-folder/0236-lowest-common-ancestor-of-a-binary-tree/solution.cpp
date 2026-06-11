class Solution {
public:
    TreeNode* f(TreeNode*root,TreeNode*&p,TreeNode*&q){
        if(!root) return nullptr;
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* l=f(root->left, p, q);
        TreeNode* r=f(root->right, p, q);
        if (l&&r) return root;
        return l?l:r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p) return p;
        if(root==q) return q;
        bool d1=false;
        bool d2=false;
        return f(root,p,q);
    }
};
