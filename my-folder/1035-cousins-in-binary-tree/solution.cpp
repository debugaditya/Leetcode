class Solution {
public:
    void f(TreeNode* root, int x, int y,vector<int>&v,int index){
        if(v.size()==4) return;
        if(root==nullptr) return;
        if ((root->left && (root->left->val == x || root->left->val == y)) ||(root->right && (root->right->val == x || root->right->val == y))){
            v.push_back(index+1);
            v.push_back(root->val);
        }
        f(root->left,x,y,v,index+1);
        f(root->right,x,y,v,index+1);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int>v;
        int index=0;
        f(root,x,y,v,index);
        if(v.size()<4) return false;
        if(v[0]==v[2]&&v[1]!=v[3]) return true;
        return false;
    }
};
