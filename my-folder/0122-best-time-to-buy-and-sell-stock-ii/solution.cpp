class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        dp[prices.size()][1]=0;
        dp[prices.size()][0]=0;
        for(int i1=prices.size()-1;i1>=0;i1--){
            for(int i2=0;i2<=1;i2++){
                if(i2==0) dp[i1][i2]=max(dp[i1+1][1]-prices[i1],dp[i1+1][0]);
                else dp[i1][i2]=max(dp[i1+1][1],dp[i1+1][0]+prices[i1]);
            }
        }
        return dp[0][0];
    }
};
