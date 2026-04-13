class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini=INT_MAX,ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(abs(i-start)<nums.size()&&mini>=nums[abs(i-start)]){
                    ans=min(ans,abs(i-start));
                    mini=nums[abs(i-start)];
                }
            }
        }
        return ans;
    }
};
