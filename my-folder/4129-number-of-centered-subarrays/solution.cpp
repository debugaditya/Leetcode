class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp; int ans=0;
        for(int i=0;i<nums.size();i++) mp[i]=mp[i-1]+nums[i];
        for(int i=0;i<nums.size();i++) for(int j=i;j<nums.size();j++){int sum=mp[j]-mp[i-1]; for(int k=i;k<=j;k++) if(nums[k]==sum){ans++; break;}}
        return ans;
    }
};

