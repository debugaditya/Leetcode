class Solution {
public:
    const int MOD=1000000007; vector<vector<vector<int>>>dp;
    int f(int i,int j,int sum,vector<vector<int>>& grid, int &k){
        if(i==grid.size()||j==grid[0].size()) return 0;
        sum+=grid[i][j]; sum%=k;
        if(i==grid.size()-1&&j==grid[0].size()-1) return sum==0;
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        long long ans=0; ans=(ans+f(i+1,j,sum,grid,k))%MOD; ans=(ans+f(i,j+1,sum,grid,k))%MOD;
        return dp[i][j][sum]=ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,-1)));
        return f(0,0,0,grid,k);
    }
};
