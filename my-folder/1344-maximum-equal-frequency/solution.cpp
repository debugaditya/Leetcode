class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int>mp,cnt; int ans=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++; cnt[mp[nums[i]]]++; cnt[mp[nums[i]]-1]--;
            maxi=max(maxi,mp[nums[i]]);
            if(maxi==1||(cnt[maxi]==1&&(maxi-1)*mp.size()==i)||(cnt[1]==1&&maxi*(mp.size()-1)==i)) ans=max(ans,i+1);
            
        }
        return ans;
    }
};
