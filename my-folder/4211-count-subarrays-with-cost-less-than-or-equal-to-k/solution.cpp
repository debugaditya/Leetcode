class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0; int l=0,r=0; priority_queue<int>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2; unordered_map<int,int>mp;
        mp[nums[0]]=1; pq1.push(nums[0]); pq2.push(nums[0]);
        while(r<nums.size()){
            while(!pq1.empty()&&mp[pq1.top()]==0) pq1.pop();
            while(!pq2.empty()&&mp[pq2.top()]==0) pq2.pop();
            long long cost=1LL*(pq1.top()-pq2.top())*(r-l+1);
            if(cost<=k){
                ans+=r+1-l;
                r++; if(nums.size()==r) break;
                mp[nums[r]]++; pq1.push(nums[r]); pq2.push(nums[r]);
            }
            else{
                mp[nums[l]]--;
                l++; r=max(l,r);
            }
        }
        return ans;
    }
};
