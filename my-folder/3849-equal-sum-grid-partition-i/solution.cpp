class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(); vector<long long>row(m,0),col(n,0); long long sum=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {row[i]+=grid[i][j]; col[j]+=grid[i][j]; sum+=grid[i][j];}
        for(int i=1;i<m;i++) row[i]+=row[i-1]; for(int i=0;i<m;i++) if(row[i]==sum-row[i]) return true;
        for(int i=1;i<n;i++) col[i]+=col[i-1]; for(int i=0;i<n;i++) if(col[i]==sum-col[i]) return true;
        return false;
    }
};
