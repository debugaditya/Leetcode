class Solution {
public:
    void bfs(vector<vector<int>>&adj,int nd,vector<int>&vis){
        queue<int>q; q.push(nd); vis[nd]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==-1){
                    for(auto &it1:vis) it1=1;
                    return;
                }
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>>adj(n); vector<int>ans;
        for(auto it:inv) adj[it[0]].push_back(it[1]);
        queue<int>q; vector<int>vis(n,0);
        q.push(k); vis[k]=-1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it]=-1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++) if(vis[i]==0) bfs(adj,i,vis);
        for(int i=0;i<n;i++) if(vis[i]==1) ans.push_back(i);
        return ans;
    }
};
