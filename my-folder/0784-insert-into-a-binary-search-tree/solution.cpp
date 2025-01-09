class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* a=root;
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;
        while(root){
            if (val > root->val) {
                if (root->right == nullptr) {
                    root->right = newNode; 
                    break;
                }
                root = root->right;
            } 
            else {
                if (root->left == nullptr) {
                    root->left = newNode; 
                    break;
                }
                root = root->left;
            }
        }
        return a;
    }
};
