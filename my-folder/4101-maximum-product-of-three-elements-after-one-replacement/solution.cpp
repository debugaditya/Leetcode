class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(auto &it:nums) if(it<0) it*=-1;
        sort(nums.begin(),nums.end());
        return 1LL*100000*nums.back()*nums[nums.size()-2];
    }
};
