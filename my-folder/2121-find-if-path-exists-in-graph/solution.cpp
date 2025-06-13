class Solution {
public:
    bool f(vector<vector<int>>&adj,int node,int d,vector<int>&vis){
        if(node==d) return true;
        vis[node]=1; bool ans=false;
        for(auto it:adj[node]) if(!vis[it]) ans|=f(adj,it,d,vis);
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int d) {
        vector<vector<int>>adj(n); vector<int>vis(n);
        for(auto it:edges){adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);}
        return f(adj,src,d,vis);
    }
};
