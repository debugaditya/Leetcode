class Solution {
public:
    long long f(vector<int>& nums1,vector<int>& nums2,int i,int j,int k,vector<vector<vector<long long>>>&dp){
        if(k==0) return 0;
        if(i==nums1.size()||j==nums2.size()) return LLONG_MIN;
        if(dp[i][j][k]!=LLONG_MIN+1) return dp[i][j][k];
        long long pick=f(nums1,nums2,i+1,j+1,k-1,dp);
        if(pick!=LLONG_MIN) pick+=1LL*nums1[i]*nums2[j];
        long long not_pick_i=f(nums1,nums2,i+1,j,k,dp);
        long long not_pick_j=f(nums1,nums2,i,j+1,k,dp);
        return dp[i][j][k]=max({pick,not_pick_i,not_pick_j});
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<vector<long long>>>dp(nums1.size(),vector<vector<long long>>(nums2.size(),vector<long long>(k+1,LLONG_MIN+1)));
        return f(nums1,nums2,0,0,k,dp);
    }
};
