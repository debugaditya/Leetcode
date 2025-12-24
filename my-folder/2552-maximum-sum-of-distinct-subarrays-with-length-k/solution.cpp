class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int>mp(*max_element(nums.begin(),nums.end())+1,0); long long uniq=0,sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++; sum+=nums[i];
            if(mp[nums[i]]==1) uniq++;
            if(i>=k){mp[nums[i-k]]--; sum-=nums[i-k]; if(mp[nums[i-k]]==0) uniq--;}
            if(uniq==k) ans=max(ans,sum); 
        }
        return ans;
    }
};
