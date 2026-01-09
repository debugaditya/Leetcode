class Solution {
public:
    int cnt=0;
    void depth(TreeNode* root,int dep,int &ans){
        if(!root) return;
        if(dep>ans) cnt=1; if(dep==ans) cnt++; 
        ans=max(ans,dep);
        depth(root->left,dep+1,ans);
        depth(root->right,dep+1,ans);
    }
    int f(TreeNode* root,int depth,int dep,TreeNode* &ans){
        if(!root||ans!=nullptr) return 0;
        if(depth==dep){if(cnt==1) ans=root; return cnt==1?0:1;}
        int left=f(root->left,depth+1,dep,ans);
        int right=f(root->right,depth+1,dep,ans);
        if(left+right==cnt) {ans=root; return 0;}
        return left+right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root->left&&!root->right) return root;
        int dep=0; TreeNode* ans=nullptr;
        depth(root,0,dep);
        f(root,0,dep,ans);
        return ans;
    }
};
