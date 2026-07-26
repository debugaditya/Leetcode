class Solution {
public:
    long long f(int i,int tight,string& num,string& s,int &limit,long long dp[16][2],long long &nums,long long &x){
        if(num.size()<s.size()||nums<x) return 0;
        if(i==num.size()) return 1;
        if(dp[i][tight]!=-1) return dp[i][tight];
        long long ans=0;
        int mini=0,maxi=tight?min(num[i]-'0',limit):9;
        if(num.size()-i<=s.size()){
            mini=s[i+s.size()-num.size()]-'0';
            maxi=mini;
        }
        for(int j=mini;j<=maxi;j++){
            if(tight&&j>num[i]-'0'||j>limit) break;
            ans+=f(i+1,tight&&j==num[i]-'0',num,s,limit,dp,nums,x);
        }
        return dp[i][tight]=ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long dp1[16][2],dp2[16][2];
        string s1=to_string(start-1),s2=to_string(finish);
        memset(dp1,-1,sizeof(dp1)); memset(dp2,-1,sizeof(dp2));
        long long x=stoll(s); start--;
        return f(0,1,s2,s,limit,dp2,finish,x)-f(0,1,s1,s,limit,dp1,start,x);
    }
};
