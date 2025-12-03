class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int idx1,idx2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) idx1=i;
            if(nums[i]==nums.size()) idx2=i;
        }
        return idx1+nums.size()-1-idx2-(idx1>idx2?1:0);
    }
};
