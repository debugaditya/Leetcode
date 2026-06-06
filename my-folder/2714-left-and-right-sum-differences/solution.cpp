class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left=0,right=0;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]+=left;
            ans[nums.size()-1-i]-=right;
            if(i>=nums.size()/2){
                ans[i]=abs(ans[i]);
                ans[nums.size()-1-i]=abs(ans[nums.size()-1-i]);
            }
            left+=nums[i];
            right+=nums[nums.size()-1-i];
        }
        return ans;
    }
};
