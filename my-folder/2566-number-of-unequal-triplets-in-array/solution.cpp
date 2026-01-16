class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans=0; unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                ans+=i*(nums.size()-i-mp[nums[i]])*mp[nums[i]];
            }
        }
        return ans;
    }
};
