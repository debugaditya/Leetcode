class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int and1=INT_MAX,ans=1;
        for(auto it:nums) and1&=it;
        if(and1>0) return ans;
        vector<int>mp(nums.size()); and1=INT_MAX;
        for(int i=0;i<nums.size();i++){
            and1&=nums[nums.size()-1-i];
            mp[nums.size()-1-i]=and1;
        } and1=INT_MAX;
        for(int i=0;i<nums.size()-1;i++) {and1&=nums[i]; if(and1==0&&mp[i+1]==0) {ans++; and1=INT_MAX;}} 
        return ans;
    }
};
