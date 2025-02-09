class Solution {
public:
    int rev(int t){
        int ans=0;
        while(t>0){
            ans = ans * 10 + t%10;  
            t/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int MOD=1e9+7;
        int a=0;
        for(int i=0;i<nums.size();i++){
            int diff=nums[i]-rev(nums[i]);
            a=(a+mp[diff])%MOD;
            mp[diff]++;
        }
        return a%MOD;
    }
};
