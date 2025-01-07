class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && (root->left || root->right)){
            if(val==root->val) return root;
            else if(val>root->val) root=root->right;
            else if(val<root->val) root=root->left;
        }
        if(root&&root->val==val) return root;
        return nullptr;
    }
};
