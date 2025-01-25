class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        for(int i=0;i<=word1.size();i++) dp[i][0]=0;
        for(int i=0;i<=word2.size();i++) dp[0][i]=0;
        for(int i1=1;i1<=word1.size();i1++){
            for(int i2=1;i2<=word2.size();i2++){
                if(word1[i1-1]==word2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                else  dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        int s=dp[word1.size()][word2.size()];
        return word1.size()+word2.size()-(2*s);
    }
};
