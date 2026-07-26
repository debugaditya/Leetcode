class Solution {
public:
    int f(int i,int even,int odd,int tight,int zero,int mod,int dp[10][10][10][2][2][20],string &s,int &k){
        if(i==s.size()) return mod==0&&even==odd;
        if(dp[i][even][odd][tight][zero][mod]!=-1) return dp[i][even][odd][tight][zero][mod];
        int ans=0,lim=tight?s[i]-'0':9;
        for(int j=0;j<=lim;j++){
            int neven=even,nodd=odd,nmod=mod;  
            if(!zero||j>0) neven+=1-j%2; nodd+=j%2;
            nmod*=10; nmod+=j; nmod%=k;
            ans+=f(i+1,neven,nodd,tight&&j==s[i]-'0',zero&&j==0,nmod,dp,s,k);
        }
        return dp[i][even][odd][tight][zero][mod]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int dp1[10][10][10][2][2][20]; int dp2[10][10][10][2][2][20];
        memset(dp1,-1,sizeof(dp1)); memset(dp2,-1,sizeof(dp2));
        string s1=to_string(high),s2=to_string(low-1);
        return f(0,0,0,1,1,0,dp1,s1,k)-f(0,0,0,1,1,0,dp2,s2,k);
    }
};
