class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0; vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-1&&nums[nums[i]-1]!=-1){
                int idx=nums[i]-1;
                while(nums[idx]!=-1){
                    int temp=nums[idx]-1; nums[idx]=-1;
                    idx=temp;
                }
            }
        } 
        for(int i=0;i<nums.size();i++) if(nums[i]!=-1) ans.push_back(i+1);
        return ans;
    }
};
