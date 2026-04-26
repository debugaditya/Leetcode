class Solution {
public:
    bool ans=false;
    vector<vector<int>>dire={{0,1},{1,0},{-1,0},{0,-1}};
    void f(vector<vector<char>>& grid,int i,int j,int dir,vector<vector<int>>&vis){
        if(ans) return;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            if(dir==k) continue;
            int new_i=i+dire[k][0],new_j=j+dire[k][1];
            if(new_i<grid.size()&&new_i>=0&&new_j<grid[0].size()&&new_j>=0){
                if(vis[new_i][new_j]&&grid[i][j]==grid[new_i][new_j]){
                    ans=true; 
                    return;
                }
                else if(grid[new_i][new_j]==grid[i][j]) f(grid,new_i,new_j,3-k,vis);
            }
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]) f(grid,i,j,-1,vis);
                if(ans) return true;
            }
        }
        return false;
    }
};
