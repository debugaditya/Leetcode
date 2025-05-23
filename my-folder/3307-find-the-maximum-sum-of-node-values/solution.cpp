class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0,mini=LLONG_MAX,cnt=0;
        for(auto it:nums){
            ans+=it;
            if((k^it)>it){
                ans+=(k^it)-it;
                cnt++;
            }
            mini=min(mini,1LL*abs((k^it)-it));
        }
        if(cnt%2==1) ans-=mini;
        return ans;
    }
};
