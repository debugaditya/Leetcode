class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l=0,r=0,sum=nums[0],ans=nums.size()+1; unordered_map<int,int>mp; mp[nums[0]]=1;
        while(r<nums.size()){
            if(sum>=k){
                ans=min(ans,r-l+1);
                mp[nums[l]]--;
                if(mp[nums[l]]==0) sum-=nums[l];
                l++; if(l>r) return 1;
            }
            else{
                r++;
                if(r<nums.size()) mp[nums[r]]++;
                if(r<nums.size()&&mp[nums[r]]==1) sum+=nums[r];
            }
        }
        return ans==nums.size()+1?-1:ans;
    }
};
