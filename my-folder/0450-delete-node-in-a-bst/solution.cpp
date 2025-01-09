class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // Base case: empty tree

        if (key < root->val) {
            // Key is in the left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Key is in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete
            if (!root->left && !root->right) {
                // Case 1: No children (leaf node)
                delete root;
                return nullptr;
            } else if (!root->left) {
                // Case 2: Only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                // Case 2: Only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 3: Two children
                TreeNode* successor = getMin(root->right); // Find inorder successor
                root->val = successor->val; // Replace value
                root->right = deleteNode(root->right, successor->val); // Delete successor
            }
        }

        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) {
            node = node->left; // Find the leftmost node
        }
        return node;
    }
};

