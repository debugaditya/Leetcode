class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp; int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp.count(nums[i]-1)) ans=max(ans,mp[nums[i]]+mp[nums[i]-1]);
            if(mp.count(nums[i]+1)) ans=max(ans,mp[nums[i]]+mp[nums[i]+1]);
        } 
        return ans;
    }
};
