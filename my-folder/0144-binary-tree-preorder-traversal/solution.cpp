class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);  // Call a helper function to handle recursion
        return result;
    }

private:
    void helper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;  // Base case for recursion
        result.push_back(node->val);  // Process the current node
        helper(node->left, result);   // Traverse the left subtree
        helper(node->right, result);  // Traverse the right subtree
    }
};

