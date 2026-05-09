class Solution {
public:
    void rotate(vector<vector<int>>& grid,int tot,int layer,int m,int n){
        while(tot--){
            int p=layer-1,q=layer-1,temp=grid[p][q];
            while(p<m-layer) {swap(grid[p+1][q],temp); p++;}
            while(q<n-layer) {swap(grid[p][q+1],temp); q++;}
            while(p>=layer) {swap(grid[p-1][q],temp); p--;}
            while(q>=layer) {swap(grid[p][q-1],temp); q--;}
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),tot=min(m,n)/2;
        for(int layer=1;layer<=tot;layer++){
            int t=k%(2*(m+n-4*(layer-1)-2));
            rotate(grid,t,layer,m,n);
        }
        return grid;
    }
};
