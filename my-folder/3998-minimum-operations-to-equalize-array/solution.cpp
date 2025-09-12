class Solution {
public:
    int minOperations(vector<int>& nums) {
        for(auto it:nums) if(it!=nums[0]) return 1;
        return 0;
    }
};
