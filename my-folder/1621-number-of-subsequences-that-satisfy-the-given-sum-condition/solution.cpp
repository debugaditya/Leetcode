class Solution {
public:
    long long modPow(long long base, int exp, int mod = 1000000007) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); long long ans=0,l=0,r=nums.size()-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans = (ans + modPow(2, r - l)) % 1000000007;
                l++;
            }
            else r--;
        }
        return ans;
    }
};
