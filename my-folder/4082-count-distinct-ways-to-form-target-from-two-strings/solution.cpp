class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int j,int k,string &word1, string &word2, string &target,vector<vector<vector<int>>>&dp){
        if(k==target.size()) return i&&j;
        if(i==word1.size()&&j==word2.size()) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long ans=0;
        for(int p=i;p<word1.size();p++) if(word1[p]==target[k]) ans=(ans+f(p+1,j,k+1,word1,word2,target,dp))%mod;
        for(int p=j;p<word2.size();p++) if(word2[p]==target[k]) ans=(ans+f(i,p+1,k+1,word1,word2,target,dp))%mod;
        return dp[i][j][k]=ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        vector<vector<vector<int>>>dp(word1.size()+1,vector<vector<int>>(word2.size()+1,vector<int>(target.size(),-1)));
        return f(0,0,0,word1,word2,target,dp);
    }
};
