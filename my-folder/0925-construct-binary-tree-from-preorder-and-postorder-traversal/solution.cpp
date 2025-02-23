class Solution {
public:
    void f(TreeNode* &root, vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd, unordered_map<int, int>& mp1, unordered_map<int, int>& mp2) {
        if (preStart > preEnd) return;

        root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return;

        int leftVal = preorder[preStart + 1];
        int leftPostIndex = mp2[leftVal];
        int leftSize = leftPostIndex - postStart + 1;

        f(root->left, preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftPostIndex, mp1, mp2);
        f(root->right, preorder, postorder, preStart + leftSize + 1, preEnd, leftPostIndex + 1, postEnd - 1, mp1, mp2);
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < preorder.size(); i++) {
            mp1[preorder[i]] = i;
            mp2[postorder[i]] = i;
        }
        TreeNode* root = nullptr;
        f(root, preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1, mp1, mp2);
        return root;
    }
};

