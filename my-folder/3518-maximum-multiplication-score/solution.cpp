class Solution {
public:
    long long f(vector<int>& a, vector<int>& b,int index,int turn,vector<vector<long long>>&dp){
        if(index>=b.size()) return 0;
        if(turn>=4) return 0;
        if(dp[index][turn]!=-1) return dp[index][turn];
        if(4-turn==b.size()-index){
            long long sum=0;
            for(int i=0;i<4-turn;i++) sum=sum+((long long)b[index+i]*a[turn+i]);
            return dp[index][turn]=sum;
        }
        return dp[index][turn]=max((long long)a[turn]*b[index]+f(a,b,index+1,turn+1,dp),f(a,b,index+1,turn,dp));

    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>>dp(b.size(),vector<long long>(4,-1));
        return f(a,b,0,0,dp);
    }
};
