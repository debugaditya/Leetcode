class Solution {
public:
    int f(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
        if(row>=matrix.size()||col>=matrix.size()) return INT_MAX;
        if(row==matrix.size()-1) return matrix[row][col];
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        return dp[row][col]=matrix[row][col]+min({f(matrix,row+1,col,dp),f(matrix,row+1,col-1,dp),f(matrix,row+1,col+1,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),INT_MAX));
        for(int i=0;i<matrix.size();i++){
            mini=min(f(matrix,0,i,dp),mini);
        }
        return mini;
    }
};
