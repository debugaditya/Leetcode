class Solution {
public:
    int dp[32][2][2];
    int f(int i,int prev,int tight,int dp[10][2][2],string &s){
        if(i==s.size()) return 1;
        if(dp[i][prev][tight]!=-1) return dp[i][prev][tight];
        int ans=0,lim=tight?s[i]-'0':1;
        ans+=f(i+1,0,tight&&s[i]=='0',dp,s);
        if(prev==0&&1==lim) ans+=f(i+1,1,tight&&s[i]=='1',dp,s);
        return dp[i][prev][tight]=ans;
    }
    int findIntegers(int n) {
        string s="";
        memset(dp,-1,sizeof(dp));
        while(n>0) {s+=n%2+'0'; n/=2;}
        reverse(s.begin(),s.end());
        return f(0,0,1,dp,s);
    }
};
