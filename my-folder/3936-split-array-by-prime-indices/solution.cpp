class Solution {
public:
    void f(int n,unordered_set<int>&primes){
        vector<bool>v(n,true);
        for(int i=2;i<n;i++){
            if(v[i]) primes.insert(i);
            for(int j=i;j<n;j+=i) v[j]=false;
        }
        return;
    }
    long long splitArray(vector<int>& nums) {
        unordered_set<int>primes; f(nums.size(),primes); long long diff=0;
        for(int i=0;i<nums.size();i++){
            if(primes.count(i)) diff+=nums[i];
            else diff-=nums[i];
        }
        return abs(diff);
    }
};
