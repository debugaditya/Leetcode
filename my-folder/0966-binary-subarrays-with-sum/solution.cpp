class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>mp(nums.size()+goal+1,0);
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==goal) ans++;
            ans+=mp[sum];
            mp[sum+goal]++;
        }
        return ans;
    }
};
