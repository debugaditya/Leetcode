class Solution {
public:
    const int mod=1e9+7;
    long long f(int i,int g1,int g2,vector<int>& nums,vector<vector<vector<int>>>&dp){
        if(i==nums.size()) return (g1==g2&&g1<201);
        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
        long long ans=f(i+1,g1,g2,nums,dp); ans%=mod;
        ans+=f(i+1,g1==201?nums[i]:gcd(g1,nums[i]),g2,nums,dp); ans%=mod;
        ans+=f(i+1,g1,g2==201?nums[i]:gcd(g2,nums[i]),nums,dp); ans%=mod;
        return dp[i][g1][g2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(202,vector<int>(202,-1)));
        return f(0,201,201,nums,dp);
    }
};
