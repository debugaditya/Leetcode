class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int diff=nums[i]-i;
            ans+=mp[diff];
            mp[diff]++;
        }
        return (nums.size()*(nums.size()-1)/2)-ans;
    }
};
