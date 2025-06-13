class Solution {
public:
    int size(vector<vector<int>>&adj,int node,vector<int>&dp){
        if(dp[node]!=-1) return dp[node];
        int sum=1;
        for(auto it:adj[node]) sum+=size(adj,it,dp);
        return dp[node]=sum;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>>adj(parents.size()); vector<int>dp(parents.size(),-1);
        for(int i=1;i<adj.size();i++) adj[parents[i]].push_back(i);
        int total=size(adj,0,dp); int cnt=0; long long maxi=INT_MIN;
        for(int i=0;i<adj.size();i++){
            long long prod=1;
            for(auto it:adj[i]) prod*=dp[it];
            long long score=max(1,(total-dp[i]))*prod;
            if(score==maxi) cnt++;
            else if(score>maxi) cnt=1;
            maxi=max(score,maxi);
        }
        return cnt;
    }
};
