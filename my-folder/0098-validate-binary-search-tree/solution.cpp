class Solution {
public:
    void inorder(TreeNode* root,bool &d,long long &maxi){
        if(!root) return;
        if(!d) return;
        inorder(root->left,d,maxi);
        if(maxi>=root->val) d=false;
        else maxi=root->val;
        inorder(root->right,d,maxi);
        return;
    }
    bool isValidBST(TreeNode* root) {
        long long maxi=LLONG_MIN;
        bool d= true;
        inorder(root,d,maxi);
        return d;
    }
};
