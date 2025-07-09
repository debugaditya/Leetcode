class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int node,int&cnt){
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=true;
                cnt++;
                dfs(adj,vis,it,cnt);
            }
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n); vector<bool>vis(n,false); long long ans=0; int cnt=0,sum=0;
        for(auto it:edges) {adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);}
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt=1; vis[i]=true;
                dfs(adj,vis,i,cnt);
                ans+=1LL*sum*cnt;
                sum+=cnt;
            }
        }
        return ans;
    }
};
