class Solution {
public:
    TreeNode* recoverFromPreorder(string t) {
        TreeNode* ans = new TreeNode(0);
        int cnt = 0;
        TreeNode* prev = ans;
        unordered_map<int, TreeNode*> mp;
        mp[0] = ans;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '-') {
                cnt++;
            } else {
                int val = 0;
                while (i < t.size() && isdigit(t[i])) {
                    val = val * 10 + (t[i] - '0');
                    i++;
                }
                i--;
                TreeNode* cur = new TreeNode(val);
                mp[cnt] = cur;
                if (mp.count(cnt - 1)) {
                    if (!mp[cnt - 1]->left) mp[cnt - 1]->left = cur;
                    else mp[cnt - 1]->right = cur;
                }
                cnt = 0;
            }
        }
        return mp[0];
    }
};

