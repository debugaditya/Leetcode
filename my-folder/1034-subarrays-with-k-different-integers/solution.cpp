class Solution {
public:
    int f(vector<int>& nums, int k){
        vector<int>mp(20001,0); int cnt=1,l=0,r=0,ans=0; mp[nums[0]]++;
        while(r<nums.size()){
            if(cnt>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) cnt--;
                l++;
                if(l>r) {r=l; cnt=1; if(r<nums.size()) mp[nums[r]]++;}
            }
            else{
                ans+=r-l+1;
                r++;
                if(r<nums.size()) {mp[nums[r]]++; if(mp[nums[r]]==1) cnt++;}
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};
