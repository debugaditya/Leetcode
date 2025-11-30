class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int>mp(nums.size()+1); mp[nums.size()]=0; long long sum=0; int ans=nums.size();
        unordered_map<int,int>mp2; mp2[0]=-1;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            mp[i]=sum%p;
        } sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int mod=(p-mp[i+1])%p;
            mp2[sum%p]=i;
            if(mp2.count(mod)) ans=min(i-mp2[mod],ans);
        }
        return ans==nums.size()?-1:ans;
    }
};
