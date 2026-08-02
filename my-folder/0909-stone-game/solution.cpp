class Solution {
public:
    int dp[501][501][2];
    int f(int i,int j,int turn,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        int ans1=f(i+1,j,1-turn,nums)+(turn?-nums[i]:nums[i]);
        int ans2=f(i,j-1,1-turn,nums)+(turn?-nums[j]:nums[j]);
        if(turn) return dp[i][j][turn]=min(ans1,ans2);
        return dp[i][j][turn]=max(ans1,ans2);
    }
    bool stoneGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums.size()-1,0,nums)>0;
    }
};
