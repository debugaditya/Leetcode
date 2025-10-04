class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0; bool d=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0) d=true;
            if(d&&nums[i]!=nums[i+1]) ans++;
        }
        if(nums.back()==0) d=true;
        if(!d) return 0;
        return ans+1;
    }
};
