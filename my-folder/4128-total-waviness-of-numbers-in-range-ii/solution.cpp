class Solution {
public:
    long long dp1[16][10][10][2][2];
    long long dp2[16][10][10][2][2];
    long long ways1[16][10][10][2][2];
    long long ways2[16][10][10][2][2];
    pair<long long,long long> f(int i,int prev1,int prev2,int tight,int zero,string &s,long long dp[16][10][10][2][2],long long ways[16][10][10][2][2]){
        if(i==s.size()) return {0,!zero};
        if(dp[i][prev1][prev2][tight][zero]!=-1) return {dp[i][prev1][prev2][tight][zero],ways[i][prev1][prev2][tight][zero]};
        long long ans=0,maxi=tight?s[i]-'0':9,w=0;
        for(int j=0;j<=maxi;j++){
            long long peak=0;
            if(!zero&&((prev1>j&&prev1>prev2)||(prev1<prev2&&prev1<j))) peak++;
            pair<long long,long long>p=f(i+1,j,prev1,tight&&j==maxi,zero&&prev1==0,s,dp,ways);
            ans+=1ll*peak*p.second+p.first;
            w+=p.second;
        }
        dp[i][prev1][prev2][tight][zero]=ans; ways[i][prev1][prev2][tight][zero]=w;
        return {dp[i][prev1][prev2][tight][zero],ways[i][prev1][prev2][tight][zero]};
    }
    long long totalWaviness(long long num1, long long num2) {
        num1--; string s1=to_string(num1),s2=to_string(num2);
        memset(dp1,-1,sizeof(dp1)); memset(dp2,-1,sizeof(dp2));
        memset(ways1,-1,sizeof(ways1)); memset(ways2,-1,sizeof(ways2));
        pair<long long,long long>p2=f(0,0,0,1,1,s2,dp2,ways2); pair<long long,long long>p1=f(0,0,0,1,1,s1,dp1,ways1);
        return p2.first-p1.first;
    }
};
