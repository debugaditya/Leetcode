class Solution {
public:
    bool f(vector<vector<int>>& grid,int row,int col){
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size()) return false;
        if(grid[row][col]==1) return true;
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        int cnt=0;
        vector<int>r(grid.size());
        vector<int>c(grid[0].size());
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==1){
                    r[row]++;
                    c[col]++;
                }
            }
        }
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==1){
                    if(r[row]>1||c[col]>1) cnt++;
                }
            }
        }
        return cnt;
    }
};
