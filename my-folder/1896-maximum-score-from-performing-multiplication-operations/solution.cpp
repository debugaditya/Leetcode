class Solution {
public:
    int f(int index,int cnt1,vector<int>& nums,vector<int>& m,vector<vector<int>>&dp){
        if(index==m.size()) return 0;
        if(dp[index][cnt1]!=INT_MIN) return dp[index][cnt1];
        int start=nums[cnt1]*m[index]+f(index+1,cnt1+1,nums,m,dp);
        int end=nums[nums.size()-1-index+cnt1]*m[index]+f(index+1,cnt1,nums,m,dp);
        return dp[index][cnt1]=max(start,end);
    }
    int maximumScore(vector<int>& nums, vector<int>& m) {
        vector<vector<int>>dp(m.size(),vector<int>(m.size(),INT_MIN));
        return f(0,0,nums,m,dp);
    }
};
