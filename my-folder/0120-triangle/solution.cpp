class Solution {
public:
    int f(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>&dp){
        if(row>=triangle.size()||col>=triangle[row].size()) return INT_MAX;
        if(row==triangle.size()-1) return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=triangle[row][col]+min(f(triangle,row+1,col,dp),f(triangle,row+1,col+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return f(triangle,0,0,dp);
    }
};
