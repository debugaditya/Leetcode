class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=nums[0],sum=nums[0],l=0,r=0; vector<int>mp(10001,0); mp[nums[0]]++;
        while(l<nums.size()){
            ans=max(ans,sum);
            if(r+1<nums.size()&&mp[nums[r+1]]==0){
                mp[nums[r+1]]++;
                sum+=nums[r+1];
                r++;
            }
            else{
                mp[nums[l]]--;
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};
