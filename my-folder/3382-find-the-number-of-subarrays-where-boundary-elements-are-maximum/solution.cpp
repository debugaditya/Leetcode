class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int>freq;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[i]>st.top()){
                freq[st.top()]--;
                st.pop();
            }
            st.push(nums[i]);
            freq[nums[i]]++;
            ans+=freq[nums[i]];
        }
        return ans;
    }
};
