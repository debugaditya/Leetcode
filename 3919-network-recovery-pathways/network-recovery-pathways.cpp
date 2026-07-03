class Solution {
public:
    bool f(int mid,vector<vector<vector<long long>>>&adj,long long &k){
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>q; 
        q.push({0,0}); vector<long long>vis(adj.size(),LLONG_MAX); vis[0]=0;
        while(!q.empty()){
            long long dist=q.top()[0];
            long long node=q.top()[1];
            q.pop();
            if(dist>vis[node]) continue;
            if(node==adj.size()-1) return true;
            for(auto &it:adj[node]) {
                if(vis[it[0]]>dist+it[1]&&it[1]>=mid&&dist+it[1]<=k) {
                    vis[it[0]]=dist+it[1]; 
                    q.push({vis[it[0]],it[0]});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& o, long long k) {
        vector<vector<vector<long long>>>adj(o.size()); int l=0,r=INT_MIN;
        for(auto &it:edges) if(o[it[0]]&&o[it[1]]) {adj[it[0]].push_back({it[1],it[2]}); r=max(r,it[2]);}
        if(r==INT_MIN) return -1; 
        while(l<=r){
            int mid=(r+l)/2;
            if(f(mid,adj,k)) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};