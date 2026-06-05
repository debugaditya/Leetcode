class Solution {
public:
    vector<pair<int,int>>v; int sum1=0,sum2=0;
    long long f(int t,int i,vector<vector<int>>&dp){
        if(t==0||i<0) return 0;
        if(dp[t][i]!=-1) return dp[t][i];
        long long not_take=f(t,i-1,dp);
        long long take=v[i].second+v[i].first*1ll*t+f(t-1,i-1,dp);
        return dp[t][i]=max(not_take,take);
    }
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        for(int i=0;i<nums2.size();i++) {v.push_back({nums2[i],nums1[i]}); sum1+=nums1[i]; sum2+=nums2[i];}
        sort(v.begin(),v.end()); 
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums1.size(),-1));
        for(int t=0;t<=nums1.size();t++){
            long long sum=sum1+t*sum2;
            if(sum-f(t,nums1.size()-1,dp)<=x) return t;
        }
        return -1;
    }
};
