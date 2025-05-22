class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p=1; int cnt=0;
        for(auto it:nums) {if(it!=0) p*=it; else cnt++;}
        if(cnt>1) for(int i=0;i<nums.size();i++) nums[i]=0;
        else if(cnt==1) for(int i=0;i<nums.size();i++) {if(nums[i]!=0) nums[i]=0; else nums[i]=p;}
        else for(int i=0;i<nums.size();i++) nums[i]=p/nums[i];
        return  nums;
    }
};
