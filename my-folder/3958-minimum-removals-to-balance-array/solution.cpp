class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); int ans=nums.size(),n=ans;
        for(int i=0;i<n;i++){
            int idx=upper_bound(nums.begin(),nums.end(),1LL*k*nums[i])-nums.begin();
            ans=min(ans,i+n-idx);
        }
        return ans;
    }
};
