class Solution {
public:
    int f(vector<int>& nums,int i,int a,int b,vector<int>&mp,vector<vector<vector<int>>>&dp,int &fir,int &s){
        if(i==mp.size()||a+b==2) return 0;
        if(dp[i][a][b]!=-1) return dp[i][a][b];
        int notpick=f(nums,i+1,a,b,mp,dp,fir,s),pick=0;
        if(a==0&&i+fir-1<mp.size()) pick=f(nums,i+fir,1,b,mp,dp,fir,s)-mp[i]+nums[i]+mp[i+fir-1];
        if(b==0&&i+s-1<mp.size()) pick=max(pick,f(nums,i+s,a,1,mp,dp,fir,s)-mp[i]+nums[i]+mp[i+s-1]);
        return dp[i][a][b]=max(pick,notpick);
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int fir, int s) {
        vector<int>mp(nums.size(),0); mp[0]=nums[0]; vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        for(int i=1;i<nums.size();i++) mp[i]=mp[i-1]+nums[i];
        return f(nums,0,0,0,mp,dp,fir,s);
    }
};
