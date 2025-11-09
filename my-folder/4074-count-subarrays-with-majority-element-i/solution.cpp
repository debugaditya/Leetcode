class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp; int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[i]=mp[i-1];
            if(nums[i]==target) mp[i]++;
        }
        for(int i=0;i<nums.size();i++) for(int j=i;j<nums.size();j++) if(2*(mp[j]-mp[i-1])>j-i+1) ans++;
        return ans;
    }
};
