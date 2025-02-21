class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(st.find(target-nums[i])!=st.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            st.insert(nums[i]);
            mp[nums[i]]=i;
        }
        return ans;
    }
};
