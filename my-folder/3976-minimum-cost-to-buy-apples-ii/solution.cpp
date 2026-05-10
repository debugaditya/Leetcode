class Solution {
public:
    int bfs(int src,vector<vector<vector<int>>>&adj,vector<int>& prices){
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>vis(adj.size(),vector<int>(2,INT_MAX));
        pq.push({0,src,0}); int ans=INT_MAX;
        while(!pq.empty()){
            auto [dist,node,ret]=pq.top();
            pq.pop();
            if(dist>vis[node][ret]) continue;
            if(ret==1&&node==src) return dist;
            if(ret==0&&dist+prices[node]<vis[node][1]) {vis[node][1]=dist+prices[node]; pq.push({dist+prices[node],node,1});}
            for(auto &it:adj[node]){
                if(vis[it[0]][ret]>dist+(ret==1?it[1]*it[2]:it[1])){
                    pq.push({dist+(ret==1?it[1]*it[2]:it[1]),it[0],ret});
                    vis[it[0]][ret]=dist+(ret==1?it[1]*it[2]:it[1]);
                }
            }
        }
        return -1;
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>adj(n);
        vector<int>ans;
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2],it[3]});
            adj[it[1]].push_back({it[0],it[2],it[3]});
        }
        for(int i=0;i<n;i++){
            ans.push_back(bfs(i,adj,prices));
        }
        return ans;
    }
};
