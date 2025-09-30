class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int k=nums.size()-1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<k;j++) nums[j]=(nums[j]+nums[j+1])%10;
            k--;
        }
        return nums[0];
    }
};
