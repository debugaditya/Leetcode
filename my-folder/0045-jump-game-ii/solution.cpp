class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>>q; q.push({0,0}); int n=nums.size(); vector<int>dp(n,INT_MAX); dp[0]=0;
        while(!q.empty()){
            auto [i,jump]=q.front(); q.pop();
            if(i==n-1) return jump;
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++) if(dp[j]>jump+1) {dp[j]=jump+1; q.push({j,jump+1});}
        }
        return -1;
    }
};
