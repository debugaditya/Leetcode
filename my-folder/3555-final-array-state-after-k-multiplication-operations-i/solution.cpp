class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++){
            int mini=min_element(nums.begin(),nums.end())-nums.begin();
            nums[mini]*=multiplier;
        }
        return nums;
        
    }
};
