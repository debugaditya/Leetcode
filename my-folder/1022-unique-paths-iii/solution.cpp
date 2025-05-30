class Solution {
public:
    int cnt=0;
    void f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&vis,int &ans,int dist){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()||grid[i][j]==-1) return;
        if(vis[i][j]) return;
        if(grid[i][j]==2){if(dist==cnt+1){ans++;} return;}
        vis[i][j]=1;
        f(grid,i+1,j,vis,ans,dist+1); f(grid,i,j+1,vis,ans,dist+1); f(grid,i-1,j,vis,ans,dist+1); f(grid,i,j-1,vis,ans,dist+1);
        vis[i][j]=0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int s1=-1,s2=-1; vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0)); int ans=0;
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++){if(grid[i][j]==1){s1=i; s2=j;} if(grid[i][j]==0) cnt++;}
        f(grid,s1,s2,vis,ans,0);
        return ans;
    }
};
