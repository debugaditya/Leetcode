class Solution {
public:
    unordered_map<long long,int>mp,dp; 
    int f(int num){
        if(num==1) return mp[num]-(1-mp[num]%2);
        if(dp.count(num)) return dp[num];
        int len=0; long long n=num;
        while(mp[n]>=2){
            len+=2;
            dp[num]=1;
            n*=n;
        }
        return (mp[n]==1?len+1:len-1);
    }
    int maximumLength(vector<int>& nums) {
        int ans=0;
        for(auto it:nums) mp[it]++;
        for(auto it:nums){
            ans=max(ans,f(it));
        }
        return ans;
    }
};
