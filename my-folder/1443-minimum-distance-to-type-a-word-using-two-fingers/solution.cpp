class Solution {
public:
    int dist(int a,int b){
        if(a==26||b==26) return 0;
        return abs(a/6-b/6)+abs((a%6)-(b%6));
    }
    int f(int i,int char_l,int char_r,string &word,vector<vector<vector<int>>>&dp){
        if(i==word.size()) return 0;
        if(dp[i][char_l][char_r]!=-1) return dp[i][char_l][char_r];
        int chr=word[i]-'A';
        int left=f(i+1,chr,char_r,word,dp)+dist(chr,char_l);
        int right=f(i+1,char_l,chr,word,dp)+dist(chr,char_r);
        return dp[i][char_l][char_r]=min(left,right);
    }
    int minimumDistance(string word) {
        vector<vector<vector<int>>>dp(word.size(),vector<vector<int>>(27,vector<int>(27,-1)));
        return f(0,26,26,word,dp);
    }
};
