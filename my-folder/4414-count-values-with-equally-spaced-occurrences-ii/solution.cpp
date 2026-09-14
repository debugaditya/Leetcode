class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>diff,prev,mp;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(!st.count(nums[i])) continue;
            else if(!prev.count(nums[i])) prev[nums[i]]=i;
            else if(!diff.count(nums[i])) diff[nums[i]]=i-prev[nums[i]];
            else if(i-prev[nums[i]]!=diff[nums[i]]) st.erase(nums[i]);
            prev[nums[i]]=i;
        }
        if(st.size()==0) return 0;
        int ans=st.size();
        for(auto it:st) if(mp[it]<3) ans--;
        return ans;
    }
};
