class Solution {
public:
    void dist(vector<int>&v,vector<vector<int>>&adj,int node){
        queue<pair<int,int>>q; q.push({node,0}); v[node]=0;
        while(!q.empty()){
            auto [nd,d]=q.front(); q.pop();
            if(d>v[nd]) continue;
            for(auto it:adj[nd]){
                if(d+1<v[it]){
                    v[it]=d+1;
                    q.push({it,d+1});
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dist_x(n,INT_MAX),dist_y(n,INT_MAX),dist_z(n,INT_MAX);
        dist(dist_x,adj,x); dist(dist_y,adj,y); dist(dist_z,adj,z); int cnt=0;
        for(int i=0;i<n;i++){
            int a=dist_x[i],b=dist_y[i],c=dist_z[i];
            if(1LL*a*a+1LL*b*b==1LL*c*c||1LL*c*c+1LL*b*b==1LL*a*a||1LL*a*a+1LL*c*c==1LL*b*b) cnt++;
        }
        return cnt;
    }
};
