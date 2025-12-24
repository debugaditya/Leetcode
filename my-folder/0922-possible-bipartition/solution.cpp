class Solution {
public:
    bool dfs(int i,int idx,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[i]!=-1) return idx==vis[i]; vis[i]=idx;
        for(auto it:adj[i]) if(!dfs(it,1-idx,adj,vis)) return false;
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1); vector<int>vis(n+1,-1);
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++) if(vis[i]==-1&&!dfs(i,0,adj,vis)) return false;
        return true;
    }
};
