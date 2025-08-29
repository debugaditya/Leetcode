class Solution {
public:
    double f(vector<vector<int>>& adj,int node,int t,int time,int target,vector<bool>&vis){
        int cnt=0;
        for(auto it:adj[node]) if(!vis[it]) cnt++;
        if(node==target&&(time==t||cnt==0)) return 1.0;
        if(time==t) return 0;
        double ans=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=true;
                ans+=1.0/cnt*f(adj,it,t,time+1,target,vis);
                vis[it]=false;
            }
        }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<bool>vis(n+1,false); vis[1]=true;
        vector<vector<int>>adj(n+1);
        for(auto it:edges) {adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);} 
        return f(adj,1,t,0,target,vis);
    }
};
