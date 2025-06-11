class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int>mp; priority_queue<int>pq; vector<int>ans;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            pq.push(nums[i]);
        }
        for(int i=k-1;i<nums.size();i++){
            while(mp[pq.top()]==0) pq.pop();
            ans.push_back(pq.top());
            mp[nums[i-k+1]]--;
            if(i+1<nums.size()){mp[nums[i+1]]++; pq.push(nums[i+1]);}
        }
        return ans;
    }
};
