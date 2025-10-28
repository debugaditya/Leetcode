class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0,j=0;
        for(int i=1;i<nums.size();i++) if(nums[i]>nums[j]) {ans+=1LL*nums[j]*(i-j); j=i;}
        ans+=(nums.size()-1-j)*nums[j];
        return ans;
    }
};
