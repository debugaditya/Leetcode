class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans=LLONG_MIN;
        priority_queue<int>maxi; priority_queue<int, vector<int>, greater<int>>mini;
        unordered_map<int,int>mp;
        for(int i=m-1;i<nums.size();i++){
            maxi.push(nums[i]); mini.push(nums[i]);
            mp[nums[i]]++;
        }
        for(int i=m-1;i<nums.size();i++){ 
            while(mp[maxi.top()]==0) maxi.pop();
            while(mp[mini.top()]==0) mini.pop();
            ans=max({ans,1LL*maxi.top()*nums[i-m+1],1LL*mini.top()*nums[i-m+1]});
            mp[nums[i]]--;
        }
        return ans;
    }
};
