class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>>dp(s.size()+1,vector<long long>(t.size()+1,0));
        int MOD = 1e9 + 7;
        for(int i=0;i<=s.size();i++) dp[i][t.size()]=1;
        for(int i1=s.size()-1;i1>=0;i1--){
            for(int i2=t.size()-1;i2>=0;i2--){
                if(s[i1]==t[i2]) dp[i1][i2]= (dp[i1+1][i2+1]+dp[i1+1][i2])%MOD;
                else dp[i1][i2]= dp[i1+1][i2];
            }
        }
        return dp[0][0];
    }
};
