class Solution {
public:
    int dfs(vector<vector<pair<int,int>>>&adj,int node,vector<int>& dist,vector<int>&dp){
        if(node==adj.size()-1) return 1;
        if(dp[node]!=-1) return dp[node];
        int sum=0; 
        for(auto it:adj[node]) if(dist[node]>dist[it.first]) sum=(sum+dfs(adj,it.first,dist,dp))%1000000007;
        return dp[node]=sum;
    }

    void dijkstra(int n, vector<vector<pair<int,int>>>& adj, vector<int>& dist) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[n] = 0;
        pq.push({0, n});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int countRestrictedPaths(int n, vector<vector<int>>& e) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dp(n+1,-1);
        for(auto it: e){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dijkstra(n, adj, dist);

        return dfs(adj,1,dist,dp);
    }
};

