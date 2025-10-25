class Solution {
public:
    const int MOD=1000000007;
    int power(int a,int b){
        long long ans=1;
        while(b--) ans=1LL*(ans*a)%MOD;
        return ans%MOD;
    }
    int f(vector<vector<int>>& mat,int i,int j,int hcf,vector<vector<vector<int>>>&dp){
        if(i==mat.size()-1) {if(hcf==1) return 1; return 0;}
        if(dp[i][j][hcf]!=-1) return dp[i][j][hcf];
        if(hcf==1) return dp[i][j][hcf]=power(mat[0].size(),mat.size()-i-1)%MOD;
        long long ans=0;
        for(int k=0;k<mat[0].size();k++) {ans+=1LL*f(mat,i+1,k,gcd(mat[i+1][k],hcf),dp); if(ans>=MOD) ans-=MOD;}
        return dp[i][j][hcf]=ans%MOD;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int maxi=*max_element(mat[0].begin(),mat[0].end());
        vector<vector<vector<int>>>dp(mat.size(),vector<vector<int>>(mat[0].size(),vector<int>(maxi+1,-1)));
        long long ans=0;
        for(int k=0;k<mat[0].size();k++) ans+=1LL*(f(mat,0,k,mat[0][k],dp)%MOD);
        return ans%MOD;
    }
};
