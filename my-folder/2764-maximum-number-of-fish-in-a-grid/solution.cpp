class Solution {
public:
    int f(vector<vector<int>>& grid,int i1,int i2){
        if(i1<0||i2<0||i1>=grid.size()||i2>=grid[0].size()) return 0;
        if(grid[i1][i2]==0) return 0;
        int fish=grid[i1][i2];
        grid[i1][i2]=0;
        int t=fish+f(grid,i1-1,i2)+f(grid,i1,i2-1)+f(grid,i1+1,i2)+f(grid,i1,i2+1);
        return t;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        for(int i1=0;i1<grid.size();i1++){
            for(int i2=0;i2<grid[0].size();i2++){
                if(grid[i1][i2]!=0) maxi=max(f(grid,i1,i2),maxi);
            }
        }
        return maxi;
    }
};
