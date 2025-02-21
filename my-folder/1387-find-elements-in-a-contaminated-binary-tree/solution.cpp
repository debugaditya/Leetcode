class FindElements {
public:
    TreeNode* a;
    void f(TreeNode* root){
        if(root==nullptr) return;
        if(root->left) root->left->val=2*root->val+1;
        if(root->right) root->right->val=2*root->val+2;
        f(root->left);
        f(root->right);
        return;
    }
    FindElements(TreeNode* root) {
        root->val=0;
        f(root);
        a=root;
    }
    void g(TreeNode* root,int target,bool &d){
        if(d) return;
        if(root==nullptr) return;
        if(root->val==target){
            d=true;
            return;
        }
        g(root->left,target,d);
        g(root->right,target,d);
        return;
    }
    bool find(int target) {
        bool d =false;
        g(a,target,d);
        return d;
    }
};

