class Solution {
public:
    int maxdigit(int n){
        int ans=0;
        while(n>0){
            ans=max(ans,n%10);
            n/=10;
        }
        return ans;
    }
    int maxSum(vector<int>& nums) {
        int sum=-1;
        unordered_map<int,int>mp;
        for(auto it:nums){
            int digit=maxdigit(it);
            if(mp[digit]>0) sum=max(mp[digit]+it,sum);
            mp[digit]=max(mp[digit],it);
        }
        return sum;
    }
};
