class Solution {
public:
    void f(TreeNode* root, vector<TreeNode*>& v) {
        if (!root) return;
        f(root->left, v);
        v.push_back(root);
        f(root->right, v);
        return;
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        f(root, v);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i]->val > v[i + 1]->val) {
                if (!first) {
                    first = v[i];
                    second=v[i+1];
                }    
                else second=v[i+1];            
            }
        }

        
        if (first && second) {
            swap(first->val, second->val);
        }
        return;
    }
};


