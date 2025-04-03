class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>mp(nums.size());
        long long ans=0;
        int maxi=INT_MIN;
        int maxi2=nums[0];
        for(int i=nums.size()-1;i>=0;i--){
            mp[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        for(int j=1;j<nums.size()-1;j++){
            ans=max(ans,(long long)(maxi2-nums[j])*mp[j]);
            maxi2=max(maxi2,nums[j]);
        }
        return ans;
    }
};
