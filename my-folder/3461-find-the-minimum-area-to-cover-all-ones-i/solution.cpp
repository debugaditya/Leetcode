class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row=-1,col=-1;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    row=max(row,i);
                    col=max(col,j);
                    m=min(m,i);
                    n=min(n,j);
                }
            }
        }
        
        return (row-m+1)*(col-n+1);
    }
};
