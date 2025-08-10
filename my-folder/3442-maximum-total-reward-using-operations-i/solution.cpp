class Solution {
public:
    int f(vector<int>& r,int index,int sum ,vector<vector<int>>&dp){
        if(index==r.size()) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int pick,notpick=0;
        notpick=f(r,index+1,sum,dp);
        if(sum<r[index]) pick=r[index]+f(r,index+1,sum+r[index],dp);
        return dp[index][sum]=max(pick,notpick);
    }
    int maxTotalReward(vector<int>& r) {
        vector<vector<int>>dp(r.size(),vector<int>(10000,-1));
        sort(r.begin(),r.end());
        return f(r,0,0,dp);
    }
};
