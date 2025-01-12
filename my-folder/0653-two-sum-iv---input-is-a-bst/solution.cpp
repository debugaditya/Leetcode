
class Solution {
public:
    void f(TreeNode* root, int k,set<int>&st,bool &d){
        if(!root) return;
        if(d) return;
        f(root->left,k,st,d);
        if(st.find(k-root->val)!=st.end()){
            d=true;
            return;
        }
        else st.insert(root->val);
        f(root->right, k,st,d);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        bool d=false;
        set<int>st;
        f(root,k,st,d);
        return d;
    }
};
