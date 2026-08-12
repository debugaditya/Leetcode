class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0,ans=1; unordered_map<int,int>mp; mp[nums[r]]++;
        while(r<nums.size()){
            if(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            else {ans=max(ans,r-l+1); r++; if(r<nums.size()) mp[nums[r]]++;}
        }
        return ans;
    }
};
