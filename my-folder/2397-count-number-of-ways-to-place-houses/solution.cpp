class Solution {
public:
    int f(int index,int n,vector<int>&dp){
        if(index>=n) return 1;
        if(dp[index]!=-1) return dp[index];
        return dp[index]=(f(index+1,n,dp)+f(index+2,n,dp))%1000000007;
    }
    int countHousePlacements(int n) {
        vector<int>dp(n,-1);
        int a=f(0,n,dp);
        long long ans=(1LL*a*a)%1000000007;
        return ans;
    }
};
