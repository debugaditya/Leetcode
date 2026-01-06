class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans=0,maxi=INT_MIN;
        queue<TreeNode*>q; int level=1;
        q.push(root);
        while(!q.empty()){
            int sum=0,sz=q.size();
            for(int i=1;i<=sz;i++){sum+=q.front()->val; if(q.front()->left) q.push(q.front()->left); if(q.front()->right) q.push(q.front()->right); q.pop();}
            if(sum>maxi){maxi=sum; ans=level;}
            level++;
        }
        return ans;
    }
};
