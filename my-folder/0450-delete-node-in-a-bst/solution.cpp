class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* right=root->right;
        TreeNode* lastright=root->left;
        while(lastright->right) lastright=lastright->right;
        lastright->right=right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy=root;
        if(!root) return NULL;
        if(root->val==key) return helper(root);
        while(root){
            if(root->val<key){
                if(root->right&&root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
            }
            else{
                if(root->left&&root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else root=root->left;
            }
        }
        return dummy;
    }
};
