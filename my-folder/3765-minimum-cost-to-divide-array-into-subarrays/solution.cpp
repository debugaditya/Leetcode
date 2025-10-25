class Solution {
public:
    long long f(vector<int>& nums,vector<int>& cost,int prev,int i,int &k,vector<int>&mp,vector<int>&mp1,vector<vector<long long>>&dp){
        if(i==nums.size()-1) return 1LL*(nums[i]+mp1[i]-mp1[prev]+k)*(mp[cost.size()-1]+cost.back()-mp[prev]);
        if(dp[prev][i]!=-1) return dp[prev][i];
        long long cut=1LL*(nums[i]+mp1[i]-mp1[prev]+k)*(mp[cost.size()-1]+cost.back()-mp[prev])+f(nums,cost,i+1,i+1,k,mp,mp1,dp);
        long long no_cut=f(nums,cost,prev,i+1,k,mp,mp1,dp);
        return dp[prev][i]=min(cut,no_cut);
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int sum=0; vector<vector<long long>>dp(nums.size(),vector<long long>(nums.size()-1,-1));
        vector<int>mp(cost.size(),0); for(int i=0;i<cost.size();i++){mp[i]=sum; sum+=cost[i];} sum=0;
        vector<int>mp1(cost.size(),0); for(int i=0;i<cost.size();i++){mp1[i]=sum; sum+=nums[i];}
        return f(nums,cost,0,0,k,mp,mp1,dp);
    }
};
