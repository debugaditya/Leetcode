class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]==nums[nums.size()/2]) return false;
            if(nums[r]==nums[nums.size()/2]) return false;
            l++; r--;
        }
        return true;
    }
};
