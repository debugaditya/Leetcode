class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool inc1=true,inc2=false; if(nums[1]<nums[0]) return false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return false;
            if(inc1&&nums[i]<nums[i-1]) inc1=false;
            else if(!inc1&&nums[i]>nums[i-1]) inc2=true;
            else if(inc2&&nums[i]<nums[i-1]) return false;
        }
        return inc2; 
    }
};
