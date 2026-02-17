class Solution {
public:
    long long f(vector<int>& nums, vector<int>& colors,int i,vector<long long>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long rob,norob=0;
        if(i+1<nums.size()&&colors[i]==colors[i+1]){
            rob=nums[i]+f(nums,colors,i+2,dp);
            norob=f(nums,colors,i+1,dp);
        }
        else rob=nums[i]+f(nums,colors,i+1,dp);
        return dp[i]=max(rob,norob);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long>dp(nums.size(),-1);
        return f(nums,colors,0,dp);
    }
};
