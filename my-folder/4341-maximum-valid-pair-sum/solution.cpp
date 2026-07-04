class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans=INT_MIN,maxi=nums[0];
        for(int i=k;i<nums.size();i++){
            maxi=max(maxi,nums[i-k]);
            ans=max(ans,nums[i]+maxi);
        }
        return ans;
    }
};
