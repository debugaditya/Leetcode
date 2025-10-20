class Solution {
public:
    int ans=0,maxi=0;
    void f(int a,int i,vector<int>& nums){
        if(i==nums.size()){
            if(a==maxi) ans++;
            return;
        }
        f(a,i+1,nums);
        a|=nums[i];
        f(a,i+1,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto &it:nums) maxi|=it;
        f(0,0,nums);
        return ans;
    }
};
