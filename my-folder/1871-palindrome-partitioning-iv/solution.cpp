class Solution {
public:
    bool f(string &s,int start,int partitions,vector<vector<int>>&dp,vector<vector<bool>>&pal){
        if(start>=s.size()) return 0;
        if(partitions==2) return pal[start][s.size()-1];
        if(dp[start][partitions]!=-1) return dp[start][partitions];
        bool ans=false;
        for(int i=start;i<s.size();i++) if(pal[start][i]) ans|=f(s,i+1,partitions+1,dp,pal);
        return dp[start][partitions]=ans;
    }
    bool checkPartitioning(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(3,-1));
        vector<vector<bool>>pal(s.size(),vector<bool>(s.size(),false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        pal[i][j] = true;
                    } else {
                        pal[i][j] = pal[i + 1][j - 1];
                    }
                }
            }
        }
        return f(s,0,0,dp,pal);
    }
};
