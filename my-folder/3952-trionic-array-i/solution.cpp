class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1,q=-1;
        for(int i=1;i<nums.size()-1;i++){
            if(p==-1&&nums[i]<=nums[i-1]) return false;
            else if(p!=-1&&q==-1&&nums[i]>=nums[i-1]) return false;
            else if(p!=-1&&q!=-1&&nums[i]<=nums[i-1]) return false;
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]) p=i;
            if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]) q=i;
        }
        if(p==-1||q==-1||nums.back()<=nums[nums.size()-2]) return false;
        return true;
    }
};
