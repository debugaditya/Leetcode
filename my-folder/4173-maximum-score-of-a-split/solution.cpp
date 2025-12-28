class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans=INT_MIN,mini=nums.back(); vector<long long>v(nums.size()); v[0]=nums[0];
        for(int i=1;i<nums.size();i++) v[i]=v[i-1]+nums[i];
        for(int i=nums.size()-2;i>=0;i--){
            ans=max(ans,v[i]-mini);
            mini=min(mini,1LL*nums[i]);
        }
        return ans;
    }
};
