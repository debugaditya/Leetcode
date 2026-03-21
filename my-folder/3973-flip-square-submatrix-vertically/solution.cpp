class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<k;i++) for(int j=0;j<k/2;j++) swap(grid[x+j][y+i],grid[k-1+x-j][y+i]);
        return grid;
    }
};
