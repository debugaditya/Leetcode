class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "n";
        queue<TreeNode*> st;
        string s = "";
        st.push(root);
        while (!st.empty()) {
            auto it = st.front();
            st.pop();
            if (it) {
                s += to_string(it->val) + " ";
                st.push(it->left);
                st.push(it->right);
            } else {
                s += "n ";
            }
        }
        s.pop_back(); // Remove the trailing space
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data[0] == 'n') return nullptr;
        stringstream ss(data);
        string val;
        ss >> val;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (ss >> val) {
                if (val == "n") {
                    node->left = nullptr;
                } else {
                    TreeNode* leftChild = new TreeNode(stoi(val));
                    node->left = leftChild;
                    q.push(leftChild);
                }
            }
            if (ss >> val) {
                if (val == "n") {
                    node->right = nullptr;
                } else {
                    TreeNode* rightChild = new TreeNode(stoi(val));
                    node->right = rightChild;
                    q.push(rightChild);
                }
            }
        }
        return root;
    }
};



