class Solution {
public:
    int f(int i,vector<int>&mp,vector<int>&dp,vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=1,next=-1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]%nums[i]==0){
                int temp=1+f(j,mp,dp,nums);
                if(take<temp) {take=temp; next=j;}
            }
        }
        mp[i]=next;
        return dp[i]=take;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>mp(nums.size(),-1),dp(nums.size(),-1),ans;
        sort(nums.begin(),nums.end());
        int maxi=0,start=-1; 
        for(int i=0;i<dp.size();i++){
            int len=f(i,mp,dp,nums);
            if(len>maxi){start=i; maxi=len;}
        }
        while(start>=0){
            ans.push_back(nums[start]);
            start=mp[start];
        }
        return ans;
    }
};
