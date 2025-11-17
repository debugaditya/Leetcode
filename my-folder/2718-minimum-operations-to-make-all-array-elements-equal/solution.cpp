class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end()); vector<long long>a;
        vector<long long>mp(nums.size(),0); mp[0]=nums[0];
        for(int i=1;i<mp.size();i++) mp[i]+=mp[i-1]+nums[i];
        for(auto it:queries){
            int idx=lower_bound(nums.begin(),nums.end(),it)-nums.begin(); long long ans=0;
            if(idx==nums.size()) ans=it*mp.size()-mp.back();
            else ans=1LL*idx*it-mp[idx]+nums[idx]+mp.back()-mp[idx]+nums[idx]-1LL*(nums.size()-idx)*it;
            a.push_back(ans);
        }
        return a;
    }
};
