class Solution {
public: 
    const int MOD=1000000007;
    int f(int i,int ch,int &n,vector<vector<int>>&dp){
        if(i==n) return 1;
        int ans=0;
        if(ch==-1){
            ans=(ans+f(i+1,0,n,dp))%MOD;
            ans=(ans+f(i+1,1,n,dp))%MOD;
            ans=(ans+f(i+1,2,n,dp))%MOD;
            ans=(ans+f(i+1,3,n,dp))%MOD;
            ans=(ans+f(i+1,4,n,dp))%MOD;
            return ans;
        }
        if(dp[i][ch]!=-1) return dp[i][ch];
        if(ch==0){
            ans=(ans+f(i+1,1,n,dp))%MOD;
        }
        if(ch==1){
            ans=(ans+f(i+1,0,n,dp))%MOD;
            ans=(ans+f(i+1,2,n,dp))%MOD;
        }
        if(ch==2){
            ans=(ans+f(i+1,0,n,dp))%MOD;
            ans=(ans+f(i+1,1,n,dp))%MOD;
            ans=(ans+f(i+1,3,n,dp))%MOD;
            ans=(ans+f(i+1,4,n,dp))%MOD;
        }
        if(ch==3){
            ans=(ans+f(i+1,2,n,dp))%MOD;
            ans=(ans+f(i+1,4,n,dp))%MOD;
        }
        if(ch==4){
            ans=(ans+f(i+1,0,n,dp))%MOD;
        }
        return dp[i][ch]=ans%MOD;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n,vector<int>(5,-1));
        return f(0,-1,n,dp);
    }
};
