class Solution {
public:
    long long f(int i,int j){
        return 1LL*(1LL*j*(j+1)-1LL*i*(i+1))/2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        ans+=f(0,min(k,nums[0]-1)); k-=min(k,nums[0]-1);
        for(int i=1;i<nums.size();i++){
            if(k==0) break;
            if(nums[i]==nums[i-1]) continue;
            ans+=f(nums[i-1],nums[i-1]+min(k,nums[i]-1-nums[i-1]));
            k-=min(k,nums[i]-1-nums[i-1]);
        }
        ans+=f(nums.back(),nums.back()+k);
        return ans;
    }
};
