class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq; vector<pair<int,int>>v;
        vector<int>ans;
        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});
        for(int i=1;i<=k;i++){v.push_back({pq.top().second,pq.top().first}); pq.pop();}
        sort(v.begin(),v.end());
        for(auto it:v) ans.push_back(it.second);
       
        return ans;
    }
};
