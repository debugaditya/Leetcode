class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2,int i1,int i2,vector<vector<int>>&dp){
        if(i1<0||i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(nums1[i1]==nums2[i2]) return dp[i1][i2]=1+f(nums1,nums2,i1-1,i2-1,dp);
        return 0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size(),ans=0;
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]) ans=max(ans,f(nums1,nums2,i,j,dp));
            }
        }
        return ans;
    }
};
