class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0; int mini=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            if(mini>=nums[i]) mini=nums[i];
            else{
                ans+=ceil(1.0*nums[i]/mini)-1;
                mini=nums[i]/ceil(1.0*nums[i]/mini);
            }
        }
        return ans;
    }
};
