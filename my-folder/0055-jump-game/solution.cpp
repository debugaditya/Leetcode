class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size();i++){
            if(maxi==nums.size()-1) return true;
            if(nums[i]==0&&maxi<=i) return false;
            maxi=max(maxi,i+nums[i]);
        } 
        return true;
    }
};
