class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // If both p and q are smaller than root, move to the left subtree
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both p and q are greater than root, move to the right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Otherwise, root is the LCA
            else {
                return root;
            }
        }
        return nullptr; // In case the tree is empty or nodes are not found
    }
};

