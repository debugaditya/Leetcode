class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int>mp(2*limit+1,0),v(2*limit+2,0); int ans=INT_MAX,n=nums.size()/2;
        for(int i=0;i<n;i++){
            mp[nums[i]+nums[nums.size()-1-i]]++;
            v[min(nums[i],nums[2*n-1-i])+1]++;
            v[max(nums[i],nums[2*n-1-i])+limit+1]--;
        }
        for(int i=1;i<v.size();i++) v[i]+=v[i-1];
        for(int i=2;i<=2*limit;i++) ans=min(ans,2*n-mp[i]-v[i]);
        return ans;
    }
};
