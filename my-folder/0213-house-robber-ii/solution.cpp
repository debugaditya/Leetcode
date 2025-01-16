class Solution {
public:
    int f(vector<int>& nums,int index,vector<int>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int l=f(nums,index+1,dp);
        int r=f(nums,index+2,dp)+nums[index];
        return dp[index]=max(l,r);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        vector<int>v1(nums.begin()+1,nums.end());
        vector<int>v2(nums.begin(),nums.end()-1);
        return max(f(v1,0,dp1),f(v2,0,dp2));
    }
};
