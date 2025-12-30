class Solution {
public:
    bool f(int x,int y,vector<vector<int>>& grid){
        unordered_set<int>st; int sum=grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2];
        if(sum!=grid[x+2][y]+grid[x+1][y+1]+grid[x][y+2]) return false;
        for(int i=x;i<x+3;i++){
            int s=grid[i][y]+grid[i][y+1]+grid[i][y+2];
            if(s!=sum) return false;
            for(int j=y;j<y+3;j++){
                int c=grid[x][j]+grid[x+1][j]+grid[x+2][j];
                if(c!=sum) return false;
                if(grid[i][j]==0||grid[i][j]>9) return false;
                st.insert(grid[i][j]);
            }
        }
        if(st.size()!=9) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3||grid[0].size()<3) return 0;
        int ans=0;
        for(int i=0;i<=grid.size()-3;i++){
            for(int j=0;j<=grid[0].size()-3;j++){
                if(f(i,j,grid)) ans++;
            }
        }
        return ans;
    }
};
