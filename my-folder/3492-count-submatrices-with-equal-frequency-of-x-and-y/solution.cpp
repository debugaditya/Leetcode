class Solution {
public:
    int cnt=0;
    void f(int i,int j,int sum,vector<vector<int>>&row,vector<vector<int>>&col,vector<vector<int>>&vis, vector<vector<bool>>&has_x){
        if(vis[i][j]) return; vis[i][j]=1;
        if(sum==0 && has_x[i][j]) cnt++;
        
        if(i+1<row.size()) f(i+1,j,sum+row[i+1][j],row,col,vis,has_x);
        if(j+1<col.size()) f(i,j+1,sum+col[j+1][i],row,col,vis,has_x);
    }
    
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>>row(grid.size(),vector<int>(grid[0].size())),col(grid[0].size(),vector<int>(grid.size()));
        vector<vector<bool>>has_x(grid.size(),vector<bool>(grid[0].size(), false));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                row[i][j]=(grid[i][j]=='X'?1:(grid[i][j]=='Y'?-1:0))+(j==0?0:row[i][j-1]);
                col[j][i]=(grid[i][j]=='X'?1:(grid[i][j]=='Y'?-1:0))+(i==0?0:col[j][i-1]);
                has_x[i][j] = (grid[i][j]=='X') || (i>0 && has_x[i-1][j]) || (j>0 && has_x[i][j-1]);
            }
        }
        
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        f(0,0,(grid[0][0]=='X'?1:(grid[0][0]=='Y'?-1:0)),row,col,vis,has_x);
        return cnt;
    }
};
