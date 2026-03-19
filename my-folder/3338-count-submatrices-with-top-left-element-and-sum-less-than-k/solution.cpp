class Solution {
public:
    int cnt=0;
    void f(int i,int j,int sum,vector<vector<int>>&row,vector<vector<int>>&col,int &k,vector<vector<int>>&vis){
        if(vis[i][j]||sum>k) return; vis[i][j]=1;
        if(sum<=k) cnt++;
        if(i+1<row.size()) f(i+1,j,sum+row[i+1][j],row,col,k,vis);
        if(j+1<col.size()) f(i,j+1,sum+col[j+1][i],row,col,k,vis);
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>>row(grid.size(),vector<int>(grid[0].size())),col(grid[0].size(),vector<int>(grid.size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                row[i][j]=grid[i][j]+(j==0?0:row[i][j-1]);
                col[j][i]=grid[i][j]+(i==0?0:col[j][i-1]);
            }
        }
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        f(0,0,grid[0][0],row,col,k,vis);
        return cnt;
    }
};
