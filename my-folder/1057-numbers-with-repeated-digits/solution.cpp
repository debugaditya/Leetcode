class Solution {
public:
    int dp[10][1024][2][2][2];
    int power(int j){
        if(j==0) return 1;
        int ans=power(j/2);
        ans*=ans;
        if(j%2) ans*=2;
        return ans;
    }
    int f(int i,int mask,int tight,int repeated,int zero,int dp[10][1024][2][2][2],string &s){
        if(i==s.size()) return repeated;
        if(dp[i][mask][tight][repeated][zero]!=-1) return dp[i][mask][tight][repeated][zero];
        int ans=0,lim=tight?s[i]-'0':9;
        for(int j=0;j<=lim;j++){
            int new_mask=mask,new_repeated=repeated||(mask&power(j))>0;
            if(!zero||j>0) new_mask|=power(j); 
            ans+=f(i+1,new_mask,tight&&j==s[i]-'0',new_repeated,zero&&j==0,dp,s);
        }
        return dp[i][mask][tight][repeated][zero]=ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(0,0,1,0,1,dp,s);
    }
};
