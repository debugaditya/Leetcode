class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long>dp(q.size()+1,-1);
        dp[q.size()]=0;
        for(int i=q.size()-1;i>=0;i--){
            long long take=0;
            take+=q[i][0];
            if(i+q[i][1]+1<q.size()+1) take+=dp[i+q[i][1]+1];
            dp[i]=max((long long) take,(long long) dp[i+1]);
        }
        return dp[0];
    }
};
