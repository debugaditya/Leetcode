class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=nums[0],ans=-1,l=0,r=0,tot=accumulate(nums.begin(),nums.end(),0); 
        if(tot==x) return nums.size();
        while(r<nums.size()){
            if(sum<=tot-x){
                if(sum==tot-x) ans=max(ans,r-l+1);
                r++;
                if(r<nums.size()) sum+=nums[r];
            }
            else{
                sum-=nums[l];
                l++; if(l>r) sum=l<nums.size()?nums[l]:0;
                r=max(r,l);
            }
        }
        return ans==-1?ans:nums.size()-ans;
    }
};
