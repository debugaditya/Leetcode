class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int ans=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                if(cnt>1){
                    nums.erase(nums.begin()+i+1);
                    i--;
                }
                else cnt++;
            }
            else cnt=1;
        }
        return nums.size();
    }
};
