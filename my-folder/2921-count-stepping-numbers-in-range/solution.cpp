class Solution {
public:
    const int mod=1e9+7;
    long long dp1[105][10][2][2];
    long long dp2[105][10][2][2];
    long long f(int i,int prev,int tight,int zeroes,string &s,long long dp[][10][2][2]){
        if(i==s.size()) return 1;
        if(dp[i][prev][tight][zeroes]!=-1) return dp[i][prev][tight][zeroes];
        long long ans=0;
        if(prev>0&&prev-1<=(tight?s[i]-'0':9)) ans=(ans+f(i+1,prev-1,tight&&s[i]-'0'==prev-1,0,s,dp))%mod;
        if(zeroes) for(int j=0;j<=(tight?s[i]-'0':9);j++) ans=(ans+f(i+1,j,tight&&s[i]-'0'==j,j==0,s,dp))%mod;
        if(!zeroes&&prev<9&&(!tight||prev+1<=s[i]-'0')) ans=(ans+f(i+1,prev+1,tight&&s[i]-'0'==prev+1,0,s,dp))%mod;
        return dp[i][prev][tight][zeroes]=ans;
    }
    bool check(string low){
        for(int i=1;i<low.size();i++) if(abs(low[i]-low[i-1])!=1) return false;
        return true;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        return ((f(0,0,1,1,high,dp1)-f(0,0,1,1,low,dp2)+check(low))%mod+mod)%mod;
    }
};
