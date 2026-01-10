class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        int ans=0; for(auto it:s1) ans+=it-'a'+97; for(auto it:s2) ans+=it-'a'+97;
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                if(s1[i]==s2[j]) dp[i][j]=max(dp[i][j],2*(s1[i]-'a'+97)+dp[i+1][j+1]);
            }
        }
        return ans-dp[0][0];
    }
};
