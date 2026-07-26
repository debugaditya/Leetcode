class Solution {
public:
    int mod=1e9+7;
    long long dp2[23][401][2];
    long long dp1[23][401][2];
    long long f(int i,int sum,int tight,long long dp[23][401][2],string &num,int &mini, int &maxi){
        if(i==num.size()) return sum>=mini&&sum<=maxi;
        if(sum>maxi) return 0;
        if(dp[i][sum][tight]!=-1) return dp[i][sum][tight];
        long long ans=0,lim=tight?num[i]-'0':9;
        for(int j=0;j<=lim;j++){
            ans+=f(i+1,sum+j,tight&&j==num[i]-'0',dp,num,mini,maxi);
            ans%=mod;
        }
        return dp[i][sum][tight]=ans;
    }
    bool check(string &num,int mini,int maxi){
        int sum=0;
        for(auto it:num) sum+=it-'0';
        return sum>=mini&&sum<=maxi;
    }
    int count(string num1, string num2, int mini, int maxi) {
        memset(dp1,-1,sizeof(dp1)); memset(dp2,-1,sizeof(dp2));
        return ((f(0,0,1,dp2,num2,mini,maxi)-f(0,0,1,dp1,num1,mini,maxi)+check(num1,mini,maxi))%mod+mod)%mod;
    }
};
