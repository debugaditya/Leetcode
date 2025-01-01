class Solution {
public:
    TreeNode* f(TreeNode*root,TreeNode*p,TreeNode*q,bool d1,bool d2){
        if(!root) return nullptr;
        if(root==p){
            d1=true;
            return p;
        }
        if(root==q){
            d2=true;
            return q;
        }
        if(d1) return p;
        if(d2) return q;
        TreeNode* l=f(root->left, p, q, d1, d2);
        TreeNode* r=f(root->right, p, q, d1, d2);
        if (l&&r) return root;
        return l?l:r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p) return p;
        if(root==q) return q;
        bool d1=false;
        bool d2=false;
        return f(root,p,q,d1,d2);
    }
};
