class Solution {
public:
    int f(int index,int sum,vector<int>& nums, int target,vector<vector<int>>&dp){
        if(sum==target) return 0;
        if(sum>target||index==nums.size()) return -1;
        if(dp[index][sum]!=-2) return dp[index][sum];
        int pick=f(index+1,sum+nums[index],nums,target,dp);
        if(pick!=-1) pick++;
        int notpick=f(index+1,sum,nums,target,dp);
        if(max(notpick,pick)==-1) return dp[index][sum]=-1;
        return dp[index][sum]=max(notpick,pick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-2));
        return f(0,0,nums,target,dp);
    }
};
