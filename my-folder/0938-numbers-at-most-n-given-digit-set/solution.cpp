class Solution {
public:
    int dp[10][2][2];
    int f(int i,int tight,int zero,vector<string>& digits,string &s){
        if(i==s.size()) return 1-zero;
        if(dp[i][tight][zero]!=-1) return dp[i][tight][zero];
        int ans=0,lim=tight?s[i]-'0':9;
        if(zero) ans+=f(i+1,tight&&s[i]-'0'==0,1,digits,s);
        for(auto &it:digits){
            if(stoi(it)>lim) break;
            ans+=f(i+1,tight&&stoi(it)==s[i]-'0',0,digits,s);
        }
        return dp[i][tight][zero]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return f(0,1,1,digits,s);
    }
};
