class Solution {
public:
    queue<pair<int,int>>q;
    void mini(vector<vector<int>>& grid,vector<vector<int>>&v){
        int n=grid.size();
        while(!q.empty()){
            auto [dist,idx]=q.front();
            q.pop();
            int r=idx/n,c=idx%n;
            if(v[r][c]<dist) continue;
            v[r][c]=min(dist,v[r][c]);
            if(r+1<v.size()&&v[r+1][c]>dist+1){
                v[r+1][c]=dist+1;
                q.push({dist+1,idx+n});
            }
            if(r-1>=0&&v[r-1][c]>dist+1){
                v[r-1][c]=dist+1;
                q.push({dist+1,idx-n});
            }
            if(c-1>=0&&v[r][c-1]>dist+1){
                v[r][c-1]=dist+1;
                q.push({dist+1,idx-1});
            }
            if(c+1<v.size()&&v[r][c+1]>dist+1){
                v[r][c+1]=dist+1;
                q.push({dist+1,idx+1});
            }
        }
    }
    int f(vector<vector<int>>& v){
        int n=v.size();
        priority_queue<pair<int,int>>pq; vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({v[0][0],0}); vis[0][0]=1;
        while(!pq.empty()){
            auto [dist,idx]=pq.top();
            pq.pop();
            int r=idx/n,c=idx%n;
            if(r==n-1&&c==n-1) return dist;
            if(r+1<vis.size()&&vis[r+1][c]==0){
                vis[r+1][c]=1;
                pq.push({min(dist,v[r+1][c]),idx+n});
            }
            if(r-1>=0&&vis[r-1][c]==0){
                vis[r-1][c]=1;
                pq.push({min(dist,v[r-1][c]),idx-n});
            }
            if(c-1>=0&&vis[r][c-1]==0){
                vis[r][c-1]=1;
                pq.push({min(dist,v[r][c-1]),idx-1});
            }
            if(c+1<vis.size()&&vis[r][c+1]==0){
                vis[r][c+1]=1;
                pq.push({min(dist,v[r][c+1]),idx+1});
            }
        }
        return -1;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid.size(),INT_MAX));
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid.size();j++) if(grid[i][j]==1) q.push({0,i*grid.size()+j});
        mini(grid,v);
        return f(v);
    }
};
