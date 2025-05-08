class Solution {
public:
    void f (TreeNode* root, int targetSum,int sum,bool &d){
        if(d) return;
        if(!root) return;
        sum+=root->val;
        if(sum==targetSum&&!root->left&&!root->right){
            d=true;
            return;
        }
        f(root->left,targetSum,sum,d);
        f(root->right,targetSum,sum,d);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool d=false;
        f(root,targetSum,0,d);
        return d;
    }
};
