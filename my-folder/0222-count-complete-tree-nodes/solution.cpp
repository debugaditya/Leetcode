class Solution {
public:
    void f(TreeNode* root,set<TreeNode*>&st,int &ans){
        if(!root) return;
        if(st.find(root)==st.end()){
            ans++;
            st.insert(root);
        }
        f(root->left,st,ans);
        f(root->right,st,ans);
    }
    int countNodes(TreeNode* root) {
        set<TreeNode*>st;
        int ans=0;
        f(root,st,ans);
        return ans;
    }
};
