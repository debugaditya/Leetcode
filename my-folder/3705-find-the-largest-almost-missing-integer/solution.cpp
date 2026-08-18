class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>mp(51,0);
        for(auto it:nums) mp[it]++;
        if(k==nums.size()) for(int i=50;i>=0;i--) if(mp[i]>0) return i;
        if(k==1) for(int i=50;i>=0;i--) if(mp[i]==1) return i;
        if(mp[nums[0]]==1&&mp[nums.back()]==1) return max(nums[0],nums.back());
        if(mp[nums[0]]==1) return nums[0];
        if(mp[nums.back()]==1) return nums.back();
        return -1;
    }
};
