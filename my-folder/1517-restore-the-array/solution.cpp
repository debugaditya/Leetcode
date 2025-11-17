class Solution {
public:
    const int MOD=1000000007;
    int f(int i,string &s,int&k,vector<int>&dp){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        long long num=0,ans=0;
        for(int j=i;j<s.size();j++){
            num*=10; num+=s[j]-'0';
            if(num>k) break;
            ans=(ans+f(j+1,s,k,dp))%MOD;
        }
        return dp[i]=ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.size(),-1);
        return f(0,s,k,dp);
    }
};
