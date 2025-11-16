class Solution {
public:
    long long f(int i,int tight,string &s,vector<vector<long long>>&dp){
        if(i==s.size()) return 1;
        if(dp[i][tight]!=-1) return dp[i][tight];
        long long ans=0;
        if(tight==1){
            if(s[i]!='0') ans+=(s[i]-'0'-1)*f(i+1,0,s,dp);
            else return dp[i][tight]=0;
            ans+=f(i+1,1,s,dp);
        }
        else ans+=9*f(i+1,0,s,dp);
        return dp[i][tight]=ans;
    }
    long long countDistinct(long long n) {
        string s = to_string(n);
        int len = s.size(); long long ans=0,pow=1;
        for(int i=1;i<len;i++){
            pow*=9;
            ans+=pow;
        }
        vector<vector<long long>>dp(len,vector<long long>(2,-1));
        return ans+f(0,1,s,dp);
    }
};
