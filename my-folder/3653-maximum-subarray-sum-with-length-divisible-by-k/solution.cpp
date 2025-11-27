class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN,sum=0; vector<long long>minsum(k,LLONG_MAX); 
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]; if((i+1)%k==0) ans=max(ans,sum);
            if(i>k-1&&minsum[i%k]!=LLONG_MAX) ans=max(ans,sum-minsum[i%k]);
            minsum[i%k]=min(minsum[i%k],sum);
        }
        return ans;
    }
};
