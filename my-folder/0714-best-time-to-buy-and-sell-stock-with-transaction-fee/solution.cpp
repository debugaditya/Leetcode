class Solution {
public:
    int f(vector<int>& prices,int fee,int i1,int i2,vector<vector<int>>&dp){
        if(i1>=prices.size()) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(i2==0) return dp[i1][i2]=max(f(prices,fee,i1+1,1,dp)-prices[i1],f(prices,fee,i1+1,0,dp));
        else return dp[i1][i2]=max(f(prices,fee,i1+1,1,dp),f(prices,fee,i1+1,0,dp)+prices[i1]-fee);
        return 0;
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(prices,fee,0,0,dp);
    }
};
