class Solution {
public:
    int ans=1;
    long long dfs(int i,vector<vector<int>>&adj,vector<int>& values, int k,vector<bool>&vis){
        if(vis[i]) return -1; 
        vis[i]=true; long long sum=0;
        for(auto it:adj[i]){
            long long num=dfs(it,adj,values,k,vis);
            if(num>=0) sum+=num; if(num!=-1&&num%k==0) ans++;
        }
        return sum+values[i];
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n); vector<bool>vis(n,false); 
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,adj,values,k,vis);
        return ans;
    }
};
