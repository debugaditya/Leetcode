class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>&adj,int src,vector<bool>&vis,int time){
        for(auto it:adj[src]){
            if(!vis[it.first]&&it.second>time){
                vis[it.first]=true;
                dfs(adj,it.first,vis,time);
            }
        }
        return;
    }
    bool count(vector<vector<pair<int,int>>>&adj,int mid,int k){
        vector<bool>vis(adj.size(),false);
        int cnt=0;
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                cnt++;
                if(cnt==k) return true;
                vis[i]=true;
                dfs(adj,i,vis,mid);
            }
        }
        return false;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>>adj(n); int ans=-1;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int l=0,r=1000000000;
        while(l<=r){
            int mid=(l+r)/2;
            if(count(adj,mid,k)){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        return ans;
    }
};
