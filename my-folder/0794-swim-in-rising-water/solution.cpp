class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),INT_MAX)); vis[0][0]=grid[0][0];
        while(!pq.empty()){
            auto [maxi,it]=pq.top(); pq.pop();
            auto [i,j]=it;
            if(i==grid.size()-1&&j==grid[0].size()-1) return maxi;
            if(i>0&&max(maxi,grid[i-1][j])<vis[i-1][j]) {vis[i-1][j]=max(maxi,grid[i-1][j]); pq.push({max(maxi,grid[i-1][j]),{i-1,j}});}
            if(i<vis.size()-1&&max(maxi,grid[i+1][j])<vis[i+1][j]) {vis[i+1][j]=max(maxi,grid[i+1][j]); pq.push({max(maxi,grid[i+1][j]),{i+1,j}});}
            if(j>0&&max(maxi,grid[i][j-1])<vis[i][j-1]) {vis[i][j-1]=max(maxi,grid[i][j-1]); pq.push({max(maxi,grid[i][j-1]),{i,j-1}});}
            if(j<vis[0].size()-1&&max(maxi,grid[i][j+1])<vis[i][j+1]) {vis[i][j+1]=max(maxi,grid[i][j+1]); pq.push({max(maxi,grid[i][j+1]),{i,j+1}});}
        }
        return -1;
    }
};
