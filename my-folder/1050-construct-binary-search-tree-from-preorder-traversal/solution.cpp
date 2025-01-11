class Solution {
public:
    TreeNode* f(vector<int>& preorder,int bound,int &i){
        if(i==preorder.size()||preorder[i]>bound) return nullptr;
        TreeNode* root= new TreeNode(preorder[i++]);
        root->left=f(preorder,root->val,i);
        root->right=f(preorder,bound,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int bound=INT_MAX;
        return f(preorder,bound,i);
    }
};
