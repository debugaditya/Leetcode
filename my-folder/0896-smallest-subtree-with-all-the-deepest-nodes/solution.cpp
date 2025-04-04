class Solution {
public:
    void depth(TreeNode* root,int dep,int &ans){
        if(!root) return;
        ans=max(ans,dep);
        depth(root->left,dep+1,ans);
        depth(root->right,dep+1,ans);
        return;
    }
    void seti(TreeNode* root,set<TreeNode* >&st,int ans,int depth){
        if(!root) return;
        if(depth==ans) st.insert(root);
        seti(root->left,st,ans,depth+1);
        seti(root->right,st,ans,depth+1);
        return;
    }
    int f(TreeNode* root,set<TreeNode* >&st,TreeNode* &ans,bool &d){
        if(!root) return 0;
        if(d) return 0;
        if(st.find(root)!=st.end()&&st.size()>1) return 1;
        if(st.find(root)!=st.end()&&st.size()==1){
            ans=root;
            d=true;
            return 0;
        }
        int left=f(root->left,st,ans,d);
        int right=f(root->right,st,ans,d);
        if(left+right==st.size()){
            ans=root;
            d=true;
            return 0;
        }
        return left+right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int dep=0;
        set<TreeNode*>st;
        bool d=false;
        TreeNode* ans=nullptr;
        depth(root,0,dep);
        seti(root,st,dep,0);
        f(root,st,ans,d);
        return ans;
    }
};
