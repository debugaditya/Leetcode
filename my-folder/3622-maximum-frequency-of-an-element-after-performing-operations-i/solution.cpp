class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int num) {
        sort(nums.begin(),nums.end()); int ans=0;
        vector<int>mp(nums.back()+1,0);
        for(auto &it:nums) mp[it]++;
        for(int it=nums[0];it<=nums.back();it++){
            int mini=it-k;
            int maxi=it+k;
            int total=upper_bound(nums.begin(),nums.end(),maxi)-lower_bound(nums.begin(),nums.end(),mini);
            int left=total-mp[it];
            ans=max(ans,min(num,left)+mp[it]);
        }
        return ans;
    }
};
