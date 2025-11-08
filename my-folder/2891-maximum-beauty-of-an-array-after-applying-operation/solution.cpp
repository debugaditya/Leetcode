class Solution {
public:
    int f(vector<int>&nums,int num){
        return upper_bound(nums.begin(),nums.end(),num)-nums.begin();
    }
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); int ans=0;
        for(int i=0;i<nums.size();i++) ans=max(ans,f(nums,nums[i]+2*k)-i);
        return ans;
    }
};
