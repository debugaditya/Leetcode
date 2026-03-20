class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        long long ans=0; vector<int>pre(nums.size()+1,0);
        for(auto it:req){
            pre[it[0]]++;
            pre[it[1]+1]--;
        }
        for(int i=1;i<pre.size();i++) pre[i]=pre[i]+pre[i-1];
        sort(nums.begin(),nums.end()); sort(pre.begin(),pre.end());
        for(int i=nums.size()-1;i>=0;i--) ans=(ans+1LL*pre[i+1]*nums[i])%1000000007;
        return ans;
    }
};
