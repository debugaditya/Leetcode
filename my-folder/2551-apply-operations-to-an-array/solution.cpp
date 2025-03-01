class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        for(int i=0;i<nums.size();i++) if(nums[i]!=0) ans.push_back(nums[i]);
        int t=nums.size()-ans.size();
        for(int i=1;i<=t;i++) ans.push_back(0);
        return ans;
    }
};
