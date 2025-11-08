class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        unordered_map<int,int>mp; mp[nums.size()-1]=1; int cnt=1,ans=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) mp[i]=mp[i+1]+1;
            else mp[i]=1;
        }
        for(int i=1;i<nums.size()-1;i++){
            ans=max(ans,mp[i+1]+1); ans=max(ans,cnt+1);
            if(nums[i]<nums[i-1]&&nums[i]<=nums[i+1]&&nums[i-1]<=nums[i+1]) ans=max(mp[i]+cnt,ans);
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]&&nums[i-1]<=nums[i+1]) ans=max(mp[i+1]+cnt+1,ans);
            if(nums[i-1]<=nums[i]) cnt++;
            else cnt=1;
        }
        ans=max(mp[1]+1,ans);
        ans=max(ans,cnt+1);
        return ans;
    }
};
