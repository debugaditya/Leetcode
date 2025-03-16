class Solution {
public:
    int f(TreeNode* root,map<int,int>&mp){
        if(!root) return 0;
        int sum=root->val+f(root->left,mp)+f(root->right,mp);
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxi=0;
        vector<int>ans;
        map<int,int>mp;
        int sum1=f(root,mp);
        for(auto it:mp) maxi=max(maxi,it.second);
        for(auto it:mp) if(it.second==maxi) ans.push_back(it.first);
        return ans;
    }
};
