class Solution {
public:
    vector<vector<int>> par;
    vector<int> dist;

    void markEdges(int n, vector<vector<int>>& edges){
        queue<int> q;
        vector<int> vis(n,0);
        q.push(n-1); vis[n-1]=1;

        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v:par[u]){
                mp[{u,v}]=true;
                mp[{v,u}]=true;
                if(!vis[v]) vis[v]=1, q.push(v);
            }
        }
    }

    map<vector<int>,bool> mp;

    int shortestDist(vector<vector<pair<int,int>>>& adj){
        int n=adj.size();
        dist=vector<int>(n,1e9);
        par.assign(n,{});

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(d!=dist[u]) continue;

            for(auto &it:adj[u]){
                int v=it.first,w=it.second;
                if(dist[v]>d+w){
                    dist[v]=d+w;
                    par[v].clear();
                    par[v].push_back(u);
                    pq.push({dist[v],v});
                } 
                else if(dist[v]==d+w){
                    par[v].push_back(u);
                }
            }
        }
        return dist[n-1]==1e9 ? -1 : dist[n-1];
    }

    vector<bool> findAnswer(int n,vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        int d=shortestDist(adj);
        vector<bool> ans(edges.size(),false);
        if(d<0) return ans;

        markEdges(n,edges);
        for(int i=0;i<edges.size();i++){
            ans[i]=mp[{edges[i][0],edges[i][1]}];
        }
        return ans;
    }
};

