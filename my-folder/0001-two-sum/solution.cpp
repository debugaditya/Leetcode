class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(st.find(target-nums[i])!=st.end()) return {mp[target-nums[i]],i};
            st.insert(nums[i]);
            mp[nums[i]]=i;
        }
        return ans;
    }
};
