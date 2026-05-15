class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),INT_MIN); dp.back()=nums.back();
        priority_queue<int>pq; unordered_map<int,int>mp; pq.push(nums.back()); mp[pq.top()]++;
        for(int i=nums.size()-2;i>=0;i--){
            while(mp[pq.top()]==0) pq.pop();
            dp[i]=pq.top()+nums[i];
            pq.push(dp[i]); mp[dp[i]]++;
            if(i+k<nums.size()) mp[dp[i+k]]--;
        }
        return dp[0];
    }
};
