class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,pair<int,int>>mp; int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])){
                mp[nums[i]]={-1,i};
            }
            else{
                if(mp[nums[i]].first==-1) {mp[nums[i]].first=mp[nums[i]].second; mp[nums[i]].second=i;}
                else{
                    ans=min(ans,abs(i-mp[nums[i]].first)+abs(i-mp[nums[i]].second)+abs(mp[nums[i]].first-mp[nums[i]].second));
                    mp[nums[i]].first=mp[nums[i]].second; mp[nums[i]].second=i;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
