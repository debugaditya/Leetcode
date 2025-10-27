class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=m*pow(2,n-1);
        for(int i=1;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++) if(grid[j][0]==grid[j][i]) sum++;
            ans+=max(sum,m-sum)*pow(2,n-1-i);
        }
        return ans;
    }
};
