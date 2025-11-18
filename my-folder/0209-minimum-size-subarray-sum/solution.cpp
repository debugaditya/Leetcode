class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX; int l=0,r=0,sum=nums[0];
        while(r<nums.size()){
            if(sum>=target) {ans=min(ans,r-l+1); sum-=nums[l]; l++;}
            else {r++; if(r<nums.size()) sum+=nums[r];}
        }
        return ans==INT_MAX?0:ans;
    }
};
