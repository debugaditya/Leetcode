class Solution {
public:
    int f(vector<int>& prices,int i1,int i2,int i3,vector<vector<vector<int>>>& dp){
        if(i1>=prices.size()) return 0;
        if(i3==2) return 0;
        if(dp[i1][i2][i3]!=-1) return dp[i1][i2][i3];
        if(i2==0) return dp[i1][i2][i3]=max(f(prices,i1+1,1,i3,dp)-prices[i1],f(prices,i1+1,0,i3,dp));
        else return dp[i1][i2][i3]=max(f(prices,i1+1,1,i3,dp),f(prices,i1+1,0,i3+1,dp)+prices[i1]);
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1))); 
        return f(prices,0,0,0,dp);
    }
};
