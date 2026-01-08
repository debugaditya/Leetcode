class Solution {
public:
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        if(i==-1||j==-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick_both=f(i-1,j-1,nums1,nums2,dp)+nums1[i]*nums2[j];
        int pick_i=f(i,j-1,nums1,nums2,dp);
        int pick_j=f(i-1,j,nums1,nums2,dp);
        return dp[i][j]=max({pick_both,pick_i,pick_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1)); int maxi=INT_MIN;
        for(int i=0;i<nums1.size();i++) for(int j=0;j<nums2.size();j++) maxi=max(maxi,nums1[i]*nums2[j]);
        int ans=f(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
        return ans==0?maxi:ans;
    }
};
