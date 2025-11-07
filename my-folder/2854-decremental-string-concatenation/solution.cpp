class Solution {
public:
    int f(int i,int ch1,int ch2,vector<string>&words,vector<vector<vector<int>>>&dp){
        if(i==words.size()) return 0;
        if(dp[i][ch1][ch2]!=-1) return dp[i][ch1][ch2];
        int a=f(i+1,ch1,words[i].back()-'a',words,dp)+words[i].size(),b=f(i+1,words[i][0]-'a',ch2,words,dp)+words[i].size();
        if(words[i][0]-'a'==ch2) a--; if(words[i].back()-'a'==ch1) b--;
        return dp[i][ch1][ch2]=min(a,b);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<vector<int>>>dp(words.size(),vector<vector<int>>(26,vector<int>(26,-1)));
        return f(1,words[0][0]-'a',words[0].back()-'a',words,dp)+words[0].size();
    }
};
