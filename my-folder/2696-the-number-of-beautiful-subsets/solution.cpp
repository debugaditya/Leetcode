class Solution {
public:
    int power(int it){
        if(it==0) return 1;
        int ans=power(it/2);
        ans*=ans;
        if(it%2) ans*=2;
        return ans;
    }
    int f(int i,int stat,vector<int>& nums, int &k,vector<vector<int>>&dp,vector<vector<int>>&mp){
        if(i==nums.size()) return 1;
        if((stat&power(i))!=0) return f(i+1,stat,nums,k,dp,mp);
        if(dp[i][stat]!=-1) return dp[i][stat];
        int not_taken=f(i+1,stat,nums,k,dp,mp),dup=stat;
        if(nums[i]+k<=1000) for(auto &it:mp[nums[i]+k]){int pow=power(it); if((dup&pow)==0) dup+=pow;}
        int taken=f(i+1,dup,nums,k,dp,mp);
        return dp[i][stat]=not_taken+taken;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>>mp(1001),dp(nums.size(),vector<int>(262144,-1));
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        return f(0,0,nums,k,dp,mp)-1;
    }
};
