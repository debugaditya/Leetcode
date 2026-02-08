class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=0; int ans=0;
        for(int i=nums.size()-2;i>=0;i--) {sum+=nums[i+1];if(nums[i]>sum/(nums.size()-1-i)) ans++;}
        return ans;
    }
};
