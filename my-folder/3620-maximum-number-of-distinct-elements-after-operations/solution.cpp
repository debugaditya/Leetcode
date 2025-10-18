class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int add=-k,prev; unordered_set<int>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]!=nums[i-1]) add=max(-k,prev+1-nums[i]);
            st.insert(nums[i]+add);
            prev=nums[i]+add;
            if(add<k) add++;
        }
        return st.size();
    }
};
