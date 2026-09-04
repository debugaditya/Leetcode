class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi; int mx=nums[0],mn=nums.back(),ans=-1;
        for(auto it:nums) mx=max(mx,it),maxi.push_back(mx);
        for(int i=nums.size()-1;i>=0;i--) {mn=min(mn,nums[i]); if(k>=maxi[i]-mn) ans=i;}
        return ans;
    }
};
