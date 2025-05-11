class Solution {
public:
    void f(TreeNode* root,int &h,int &cnt){
        if(!root) return;
        h++;
        if(h>cnt) {h--; return;}
        if(!root->left&&!root->right) {cnt=h; h--; return;}
        f(root->left,h,cnt);
        f(root->right,h,cnt);
        h--;
        return;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int cnt=INT_MAX;
        int h=0;
        f(root,h,cnt);
        return cnt;
    }
};
