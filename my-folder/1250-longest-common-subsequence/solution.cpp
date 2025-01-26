class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string word1=text1;
        string word2=text2;
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i1=1;i1<=word1.size();i1++){
            for(int i2=1;i2<=word2.size();i2++){
                if(word1[i1-1]==word2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                else  dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        int s=dp[word1.size()][word2.size()];
        return s;
    }
};
