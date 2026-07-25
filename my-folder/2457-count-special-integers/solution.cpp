class Solution {
public:
    int dp[10][1024][2][2];
    int power(int j){
        if(j==0) return 1;
        int ans=power(j/2);
        ans*=ans;
        if(j%2) ans*=2;
        return ans;
    }
    int f(int i,int mask,int tight,int zero,string &s,int dp[10][1024][2][2]){
        if(i==s.size()) return 1-zero;
        if(dp[i][mask][tight][zero]!=-1) return dp[i][mask][tight][zero];
        int ans=0,lim=tight?s[i]-'0':9;
        for(int j=0;j<=lim;j++){
            if((power(j)&mask)>0) continue;
            int new_mask=mask;
            if(!zero||j>0) new_mask|=power(j);
            ans+=f(i+1,new_mask,tight&&j==s[i]-'0',zero&&j==0,s,dp);
        }
        return dp[i][mask][tight][zero]=ans;
    }
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(0,0,1,1,s,dp);
    }
};
