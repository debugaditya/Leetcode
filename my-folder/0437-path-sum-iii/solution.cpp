class Solution {
public:
    void f(TreeNode* root, int targetSum,long long sum, int &cnt){
        if(!root) return;
        sum+=root->val;
        if(targetSum==sum) cnt++;
        f(root->left,targetSum,sum,cnt);
        f(root->right,targetSum,sum,cnt);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        if(!root) return 0;
        f(root,targetSum,0,cnt);
        if(root->left) cnt+=pathSum(root->left,targetSum);
        if(root->right) cnt+=pathSum(root->right,targetSum);
        return cnt;
    }
};
