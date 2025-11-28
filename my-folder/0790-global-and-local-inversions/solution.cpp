class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxi=-1;
        for(int i=1;i<nums.size();i++){
            if(maxi>nums[i]) return false;
            maxi=max(maxi,nums[i-1]); 
        }
        return true;
    }
};
