class Solution {
public:
    int f(int n, vector<int>& cuts,int start,int end,vector<vector<int>>&dp){
        if(start+1==end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int mini=INT_MAX;
        for(int i=start+1;i<end;i++){
            mini=min(mini,cuts[end]-cuts[start]+f(n,cuts,start,i,dp)+f(n,cuts,i,end,dp));
        }
        if(mini==INT_MAX) return 0;
        return dp[start][end]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return f(n,cuts,0,cuts.size()-1,dp);
    }
};
