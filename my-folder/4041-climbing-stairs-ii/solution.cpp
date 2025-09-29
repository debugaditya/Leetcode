class Solution {
public:
    vector<int>dp;
    int f(int i,vector<int>& cost){
        if(i>cost.size()) return 1000000009;
        if(i==cost.size()) return cost[i-1];
        if(dp[i]!=-1) return dp[i];
        int ans = i-1 >= 0 ? cost[i-1] : 0;
        int x = 1 + f(i+1,cost);
        int y = 4 + f(i+2,cost);
        int z = 9 + f(i+3,cost);
        return dp[i] = ans + min(x,min(y,z));

    }
    int climbStairs(int n, vector<int>& cost) {
        dp.resize(n,-1);
        return f(0,cost);
    }
};
