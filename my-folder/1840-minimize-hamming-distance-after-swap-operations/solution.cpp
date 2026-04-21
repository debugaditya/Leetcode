class Solution {
public:
    void dfs(int i,vector<int>&vis,unordered_map<int,int>&mp,vector<vector<int>>&adj,vector<int>& source, vector<int>& target){
        if(vis[i]) return;
        vis[i]=1; mp[target[i]]++; mp[source[i]]--;
        for(auto it:adj[i]) dfs(it,vis,mp,adj,source,target);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size(),ans=0;
        vector<vector<int>>adj(n);
        for(auto it:allowedSwaps){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            unordered_map<int,int>mp;
            dfs(i,vis,mp,adj,source,target);
            for(auto it:mp) ans+=it.second>0?it.second:0;
        }
        return ans;
    }
};
