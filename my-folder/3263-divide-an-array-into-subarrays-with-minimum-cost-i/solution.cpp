class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini1=51,mini2=51;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=mini1){
                mini2=mini1; 
                mini1=nums[i];
            }
            else if(nums[i]<=mini2) mini2=nums[i];
        }
        return mini1+mini2+nums[0];
    }
};
