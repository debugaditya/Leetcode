class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());int i=1;
        for(auto it:nums) if(original*i==it) i*=2;
        return original*i;
    }
};
