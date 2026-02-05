class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>r(nums.size());
        for(int i=0;i<nums.size();i++){
            int steps=abs(nums[i])%nums.size();
            r[i]=nums[(i+(nums[i]<0?-1:1)*steps+nums.size())%nums.size()];
        }
        return r;
    }
};
