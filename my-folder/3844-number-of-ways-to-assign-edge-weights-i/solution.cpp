class Solution {
public:
    const int mod=1e9+7;
    long long power(int n){
        if(n==0) return 1;
        long long temp=power(n/2);
        long long ans=1LL*(temp*temp)%mod;
        if(n%2==1) ans=(2*ans)%mod;
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>>adj(edges.size()+2);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q; vector<int>vis(adj.size(),0);
        q.push({1,0}); int height=0; vis[1]=1;
        while(!q.empty()){
            auto [node,dist]=q.front();
            q.pop();  height=max(dist,height);
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,dist+1});
                }
            }
        }
        return power(height-1);
    }
};
