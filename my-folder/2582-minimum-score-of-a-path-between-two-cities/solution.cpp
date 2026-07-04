class Solution {
public:
    int check(vector<vector<vector<int>>>&adj){
        int n=adj.size()-1,ans=INT_MAX;
        queue<int>q;
        q.push(1); vector<int>vis(n+2,0);  vis[1]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                int next=it[0],w=it[1];
                ans=min(ans,w);
                if(vis[next]==0){
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>adj(n+1); int ans=INT_MAX;
        for(auto &it:roads){
            int u = it[0],v=it[1],dist=it[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        return check(adj);
    }
};
