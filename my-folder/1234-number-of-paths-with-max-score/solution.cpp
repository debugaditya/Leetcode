class Solution {
public:
    const int mod=1e9+7;
    vector<int> f(int i,int j,vector<string>& board,vector<vector<vector<int>>>&dp){
        if(i==-1||j==-1||board[i][j]=='X') return {INT_MIN,0};
        if(i==0&&j==0) return {0,1};
        if(dp[i][j][0]!=-1) return dp[i][j];
        vector<int>left=f(i,j-1,board,dp);
        vector<int>up=f(i-1,j,board,dp);
        vector<int>dia=f(i-1,j-1,board,dp);
        long long paths=0,maxi=max({left[0],up[0],dia[0]});
        if(maxi==INT_MIN) return dp[i][j]={(int)maxi,(int)paths};
        if(left[0]==maxi) {paths+=left[1]; paths%=mod;}
        if(dia[0]==maxi) {paths+=dia[1]; paths%=mod;}
        if(up[0]==maxi) {paths+=up[1]; paths%=mod;}
        maxi+=(board[i][j]=='S'?0:(board[i][j]-'0')); maxi%=mod;
        return dp[i][j]={(int)maxi,(int)paths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<vector<int>>>dp(board.size(),vector<vector<int>>(board[0].size(),{-1,-1}));
        vector<int>a=f(board.size()-1,board[0].size()-1,board,dp);
        if(a[0]==INT_MIN) return {0,0};
        return a;  
    }
};
