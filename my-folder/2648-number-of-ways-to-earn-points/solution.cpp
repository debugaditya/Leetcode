class Solution {
public:
    int f(int i,int sum,vector<vector<int>>& types,vector<vector<int>>&dp){
        if(sum<0||i==types.size()) return sum==0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        long ans=0;
        for(int j=0;j<=types[i][0];j++){
            ans+=f(i+1,sum-j*types[i][1],types,dp);
            ans%=1000000007;
        }
        return dp[i][sum]=ans;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>>dp(types.size(),vector<int>(target+1,-1));
        return f(0,target,types,dp);
    }
};
