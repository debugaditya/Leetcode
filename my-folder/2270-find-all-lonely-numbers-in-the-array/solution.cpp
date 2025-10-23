class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if(nums.size()==1) return nums;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>ans; vector<int>mp(maxi+1,0);
        for(auto &it:nums) mp[it]++;
        if(mp[0]==1&&mp[1]==0) ans.push_back(0);
        for(int i=1;i<maxi;i++) if(mp[i]==1&&mp[i-1]==0&&mp[i+1]==0) ans.push_back(i);
        if(mp[maxi]==1&&mp[maxi-1]==0) ans.push_back(maxi);  
        return ans;
    }
};
