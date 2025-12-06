class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<bool>&vis){
        vis[i]=true;
        for(auto it:adj[i]) if(!vis[it]) dfs(it,adj,vis);
    }
    bool check(vector<vector<int>>&adj,vector<int>edge){
        for(int i=0;i<adj[edge[0]].size();i++) if(adj[edge[0]][i]==edge[1]) adj[edge[0]].erase(adj[edge[0]].begin()+i); 
        for(int i=0;i<adj[edge[1]].size();i++) if(adj[edge[1]][i]==edge[0]) adj[edge[1]].erase(adj[edge[1]].begin()+i);
        vector<bool>vis(adj.size(),false); int cnt=0;
        for(int i=1;i<adj.size();i++) if(!vis[i]) {dfs(i,adj,vis); cnt++;}
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        return cnt==1;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int>mp1(edges.size()+1,0); vector<vector<int>>adj(edges.size()+1);
        for(auto it:edges) {mp1[it[1]]++; adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);}
        for(int i=edges.size()-1;i>=0;i--) if(mp1[edges[i][1]]==2&&check(adj,edges[i])) return edges[i];
        for(int i=edges.size()-1;i>=0;i--) if(check(adj,edges[i])) return edges[i];
        return {};
    }
};
