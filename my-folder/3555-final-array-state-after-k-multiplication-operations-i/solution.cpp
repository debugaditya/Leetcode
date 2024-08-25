class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=1;i<=k;i++){
        
        auto min = min_element(nums.begin(), nums.end()); 
        *min *= multiplier;
        
        
        }
        return nums;
        
    }
};
