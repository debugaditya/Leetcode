class Solution {
public:
    long long f(vector<int>& prices, int k,int index,int d,vector<vector<vector<long long>>>&dp){
        if(k==0) return 0;
        if(dp[index][k][d]!=-1) return dp[index][k][d];
        long long ans=INT_MIN; 
        if(d==1&&index==prices.size()-1) return prices[index];
        if(d==2&&index==prices.size()-1) return -prices[index];
        if(d==0&&index==prices.size()-1) return 0;
        if(d==0) ans=max({ans,f(prices,k,index+1,1,dp)-prices[index],f(prices,k,index+1,0,dp),f(prices,k,index+1,2,dp)+prices[index]});
        if(d==1) ans=max({ans,f(prices,k,index+1,1,dp),prices[index]+f(prices,k-1,index+1,0,dp)});
        if(d==2) ans=max({ans,f(prices,k,index+1,2,dp),f(prices,k-1,index+1,0,dp)-prices[index]});
        return dp[index][k][d]=ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>>dp(prices.size(),vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return f(prices,k,0,0,dp);
    }
};
