class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>&dp){
        if(i==nums.size()) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int ans=INT_MIN,sum=0;
        for(int j=0;j<3&&i+j<nums.size();j++){
            sum+=nums[i+j];
            ans=max(ans,sum-f(i+j+1,nums,dp));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& nums) {
        vector<int>dp(nums.size(),INT_MIN);
        int dif=f(0,nums,dp);
        if(dif>0) return "Alice";
        if(dif<0) return "Bob";
        return "Tie";
    }
};
