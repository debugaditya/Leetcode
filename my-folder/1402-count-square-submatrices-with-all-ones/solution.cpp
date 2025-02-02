class Solution {
public:
    int f(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp){
        if(i>=matrix.size()||j>=matrix[0].size()) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        return dp[i][j]=1+min({f(matrix,i+1,j,dp),f(matrix,i+1,j+1,dp),f(matrix,i,j+1,dp)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=f(matrix,i,j,dp);
            }
        }
        return ans;
    }
};
