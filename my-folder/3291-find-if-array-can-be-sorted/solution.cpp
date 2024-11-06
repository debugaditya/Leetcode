class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(nums[j]>nums[j+1]){
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){
                        swap(nums[j],nums[j+1]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};
