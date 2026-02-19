class Solution {
public:
    bool mini(vector<int>& nums){
        bool d=true; int mini=INT_MAX,idx=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) d=false;
            if(nums[i]+nums[i-1]<mini) {mini=nums[i]+nums[i-1]; idx=i;}
        }
        if(d) return true;
        nums[idx-1]+=nums[idx];
        nums.erase(nums.begin()+idx);
        return false;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(nums.size()>1){
            if(mini(nums)) return cnt;
            cnt++;
        }
        return cnt;
    }
};
