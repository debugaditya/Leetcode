class Solution {
public:
    int mini(int i,int j,vector<vector<int>>& grid, int k){
        int mn=INT_MAX; if(k==1) return 0;
        for(int a=i;a<i+k;a++){
            for(int b=j;b<j+k;b++){
                for(int c=i;c<i+k;c++){
                    for(int d=j;d<j+k;d++){
                        if(grid[a][b]!=grid[c][d]) mn=min(mn,abs(grid[a][b]-grid[c][d]));
                    }
                }
            }
        }
        return mn==INT_MAX?0:mn;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++) ans[i][j]=mini(i,j,grid,k);
        }
        return ans;
    }
};
